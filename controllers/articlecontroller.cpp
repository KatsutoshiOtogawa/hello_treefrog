#include "articlecontroller.h"
#include "article.h"
#include "user.h"

bool ArticleController::preFilter()
{
    if (!isUserLoggedIn()) {
        redirect(url("Account", "form"));
        return false;
    }
    return true;
}

void ArticleController::index()
{
    auto articleList = Article::getAll();
    texport(articleList);
    render();
}

void ArticleController::show(const QString &id)
{
    auto article = Article::get(id);
    texport(article);
    render();
}

void ArticleController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto article = httpRequest().formItems("article");
        auto model = Article::create(article);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(article);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ArticleController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Article::get(id);
        if (!model.isNull()) {
            session().insert("article_lockRevision", model.lockRevision());
            auto article = model.toVariantMap();
            texport(article);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("article_lockRevision").toInt();
        auto model = Article::get(id, rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto article = httpRequest().formItems("article");
        model.setProperties(article);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(article);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ArticleController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto article = Article::get(id);
    article.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ArticleController)
