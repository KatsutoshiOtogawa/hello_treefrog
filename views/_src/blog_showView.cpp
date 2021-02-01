#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_showView : public TActionView
{
  Q_OBJECT
public:
  blog_showView() : TActionView() { }
  QString toString();
};

QString blog_showView::toString()
{
  responsebody.reserve(1576);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Blog, blog);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Blog</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.title());
  responsebody += QStringLiteral("</dd><br />\n<dt>Body</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.body());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.lockRevision());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", blog.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(blog_showView)

#include "blog_showView.moc"
