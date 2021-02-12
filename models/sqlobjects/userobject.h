#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserObject : public TSqlObject, public QSharedData
{
public:
    QString username;
    QString password;
    QString created_at;
    QString updated_at;
    int lock_revision {0};

    enum PropertyIndex {
        Username = 0,
        Password,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const override { return Username; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QStringLiteral("user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
    Q_PROPERTY(QString created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QString, created_at)
    Q_PROPERTY(QString updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QString, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // USEROBJECT_H
