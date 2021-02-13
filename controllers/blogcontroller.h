#ifndef BLOGCONTROLLER_H
#define BLOGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT BlogController : public ApplicationController
{
    Q_OBJECT
public:
    BlogController() : ApplicationController() { }

public slots:
    void index();
    void show(const QString &id);
};

struct BlogArticle
{
    unsigned int id;
    QString title;
    QString body;
    QStringList tagnames;
};

Q_DECLARE_METATYPE(BlogArticle)
Q_DECLARE_METATYPE(QList<BlogArticle>)

#endif // BLOGCONTROLLER_H
