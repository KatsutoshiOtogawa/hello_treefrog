#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_indexView : public TActionView
{
  Q_OBJECT
public:
  blog_indexView() : TActionView() { }
  QString toString();
};

QString blog_indexView::toString()
{
  responsebody.reserve(1607);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<h1>Listing Blog</h1>\n\n");
  responsebody += QVariant(linkTo("Create a new Blog", urla("create"))).toString();
  responsebody += QStringLiteral("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>Title</th>\n    <th>Body</th>\n  </tr>\n");
  tfetch(QList<Blog>, blogList);
  for (const auto &i : blogList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.title());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.body());
  responsebody += QStringLiteral("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("save", i.id()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_indexView)

#include "blog_indexView.moc"
