#include "tagcontroller.h"
#include "tag.h"


void TagController::index()
{
    auto tagList = Tag::getAll();
    texport(tagList);
    render();
}

void TagController::show(const QString &id)
{
    auto tag = Tag::get(id);
    texport(tag);
    render();
}

void TagController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto tag = httpRequest().formItems("tag");
        auto model = Tag::create(tag);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(tag);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TagController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Tag::get(id);
        if (!model.isNull()) {
            session().insert("tag_lockRevision", model.lockRevision());
            auto tag = model.toVariantMap();
            texport(tag);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("tag_lockRevision").toInt();
        auto model = Tag::get(id, rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto tag = httpRequest().formItems("tag");
        model.setProperties(tag);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(tag);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void TagController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto tag = Tag::get(id);
    tag.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(TagController)
