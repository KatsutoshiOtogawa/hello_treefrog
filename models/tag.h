#ifndef TAG_H
#define TAG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class TagObject;
class QJsonArray;


class T_MODEL_EXPORT Tag : public TAbstractModel
{
public:
    Tag();
    Tag(const Tag &other);
    Tag(const TagObject &object);
    ~Tag();

    QString id() const;
    void setId(const QString &id);
    QString name() const;
    void setName(const QString &name);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Tag &operator=(const Tag &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Tag create(const QString &id, const QString &name);
    static Tag create(const QVariantMap &values);
    static Tag get(const QString &id);
    static Tag get(const QString &id, int lockRevision);
    static int count();
    static QList<Tag> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<TagObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Tag &model);
    friend QDataStream &operator>>(QDataStream &ds, Tag &model);
};

Q_DECLARE_METATYPE(Tag)
Q_DECLARE_METATYPE(QList<Tag>)

#endif // TAG_H
