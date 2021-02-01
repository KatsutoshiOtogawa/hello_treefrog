#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_createView : public TActionView
{
  Q_OBJECT
public:
  blog_createView() : TActionView() { }
  QString toString();
};

QString blog_createView::toString()
{
  responsebody.reserve(1401);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, blog);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Blog</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input name=\"blog[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["id"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Title<br /><input name=\"blog[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["title"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Body<br /><input name=\"blog[body]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["body"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_createView)

#include "blog_createView.moc"
