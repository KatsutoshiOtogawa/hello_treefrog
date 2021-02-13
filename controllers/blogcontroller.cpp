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
    // auto article = Article::get(id);
    // texport(article);

    TSqlQuery query;
    query.prepare("\
    SELECT \
        article.id \
        ,article.title \
        ,article.body \
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
        blogarticle.tagnames = query.value(3).toString().split(",");
    }

    texport(blogarticle);
    // while (query.next()) {
// int id = query.value(0).toInt(); // 最初のフィールドをint型へ変換
//     QString str = query.value(1).toString(); // 2番目のフィールドをQString型へ変換
//     // do something
// }
    // 集合関数を使ってタグを,区切りにまとめる。group_concat(name)
    // ArticleObjectを継承という形で
//     TSqlQuery query;
// query.prepare("INSERT INTO blog (id, title, body) VALUES (:id, :title, :body)");
// query.bind(":id", 100).bind(":title", tr("Hello")).bind(":body", tr("Hello world"));
// query.exec();
// while (query.next()) {
// int id = query.value(0).toInt(); // 最初のフィールドをint型へ変換
//     QString str = query.value(1).toString(); // 2番目のフィールドをQString型へ変換
//     // do something
// }
// TSqlQueryORMapper<BlogObject> mapper;
// mapper.prepare("SELECT blog.* FROM blog WHERE ...");
// mapper.exec();  // クエリ実行

// TSqlQueryORMapperIterator<BlogObject> it(mapper);
// while (it.hasNext()) {
//     BlogObject obj = it.next();
//     // do something
//      :
// }
    render();
}

// Don't remove below this line
T_DEFINE_CONTROLLER(BlogController)
