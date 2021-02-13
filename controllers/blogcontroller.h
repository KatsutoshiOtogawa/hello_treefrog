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
    void tag(const QString &id);
};

struct BlogArticle
{
    unsigned int id;
    QString title;
    QString body;

    QStringList tagids;
    QStringList tagnames;
    // QSet<Tag> tagset;
    // QSet<QPair<unsigned int,QString>> tagset;
    
};

Q_DECLARE_METATYPE(BlogArticle)

struct TagActionData
{
    unsigned int id;
    QString name;

    QStringList articleids;
    QStringList articletitles;
    // QSet<Tag> tagset;
    // QSet<QPair<unsigned int,QString>> tagset;
    
};

Q_DECLARE_METATYPE(TagActionData)

#endif // BLOGCONTROLLER_H
