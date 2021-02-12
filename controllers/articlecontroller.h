#ifndef ARTICLECONTROLLER_H
#define ARTICLECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ArticleController : public ApplicationController
{
    Q_OBJECT
public:
    ArticleController() : ApplicationController() {}

public slots:
    void index();
    bool preFilter() override;
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // ARTICLECONTROLLER_H
