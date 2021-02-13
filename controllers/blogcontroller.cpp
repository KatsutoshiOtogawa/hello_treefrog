#include "blogcontroller.h"
#include "article.h"
#include <tsqlquery.h>

void BlogController::index()
{
    auto articleList = Article::getAll();
    texport(articleList);
    render();
}

void BlogController::show(const QString &id)
{
    TSqlQuery query;
    query.prepare("\
    SELECT \
        article.id \
        ,article.title \
        ,article.body \
        ,group_concat(tag.id, ',') AS tagids \
        ,group_concat(tag.name, ',') AS tagnames \
    FROM \
        article \
            INNER JOIN article_tag \
        ON article.id = article_tag.article_id \
            INNER JOIN tag \
        ON article_tag.tag_id = tag.id \
    WHERE \
        article.id = :id \
    GROUP BY \
        article.id \
    ;");
    query.bind(":id", id);
    query.exec();

    BlogArticle blogarticle = {};

    while (query.next()) {
        blogarticle.id = query.value(0).toInt();
        blogarticle.title = query.value(1).toString();
        blogarticle.body = query.value(2).toString();
        blogarticle.tagids = query.value(3).toString().split(",");
        blogarticle.tagnames = query.value(4).toString().split(",");
    }

    texport(blogarticle);

    render();
}

void BlogController::tag(const QString &id)
{
    TSqlQuery query;
    query.prepare("\
    SELECT \
        tag.id \
        ,tag.name \
        ,group_concat(article.id, ',') AS articleids \
        ,group_concat(article.title, ',') AS articletitles \
    FROM \
        tag \
            INNER JOIN article_tag \
        ON tag.id = article_tag.tag_id \
            INNER JOIN article \
        ON article_tag.article_id = article.id \
    WHERE \
        tag.id = :id \
    GROUP BY \
        article.id \
    ;");
    query.bind(":id", id);
    query.exec();

    TagActionData tagactiondata = {};

    while (query.next()) {
        tagactiondata.id = query.value(0).toInt();
        tagactiondata.name = query.value(1).toString();
        tagactiondata.articleids = query.value(2).toString().split(",");
        tagactiondata.articletitles = query.value(3).toString().split(",");
    }

    texport(tagactiondata);

    render();
}
// Don't remove below this line
T_DEFINE_CONTROLLER(BlogController)
