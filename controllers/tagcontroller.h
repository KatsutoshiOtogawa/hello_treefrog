#ifndef TAGCONTROLLER_H
#define TAGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT TagController : public ApplicationController
{
    Q_OBJECT
public:
    TagController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // TAGCONTROLLER_H
