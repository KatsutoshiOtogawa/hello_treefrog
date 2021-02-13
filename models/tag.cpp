#include <TreeFrogModel>
#include "tag.h"
#include "sqlobjects/tagobject.h"

Tag::Tag() :
    TAbstractModel(),
    d(new TagObject())
{
    // set the initial parameters
}

Tag::Tag(const Tag &other) :
    TAbstractModel(),
    d(other.d)
{ }

Tag::Tag(const TagObject &object) :
    TAbstractModel(),
    d(new TagObject(object))
{ }

Tag::~Tag()
{
    // If the reference count becomes 0,
    // the shared data object 'TagObject' is deleted.
}

QString Tag::id() const
{
    return d->id;
}

void Tag::setId(const QString &id)
{
    d->id = id;
}

QString Tag::name() const
{
    return d->name;
}

void Tag::setName(const QString &name)
{
    d->name = name;
}

QString Tag::createdAt() const
{
    return d->created_at;
}

QString Tag::updatedAt() const
{
    return d->updated_at;
}

int Tag::lockRevision() const
{
    return d->lock_revision;
}

Tag &Tag::operator=(const Tag &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Tag Tag::create(const QString &id, const QString &name)
{
    TagObject obj;
    obj.id = id;
    obj.name = name;
    if (!obj.create()) {
        return Tag();
    }
    return Tag(obj);
}

Tag Tag::create(const QVariantMap &values)
{
    Tag model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Tag Tag::get(const QString &id)
{
    TSqlORMapper<TagObject> mapper;
    return Tag(mapper.findByPrimaryKey(id));
}

Tag Tag::get(const QString &id, int lockRevision)
{
    TSqlORMapper<TagObject> mapper;
    TCriteria cri;
    cri.add(TagObject::Id, id);
    cri.add(TagObject::LockRevision, lockRevision);
    return Tag(mapper.findFirst(cri));
}

int Tag::count()
{
    TSqlORMapper<TagObject> mapper;
    return mapper.findCount();
}

QList<Tag> Tag::getAll()
{
    return tfGetModelListByCriteria<Tag, TagObject>(TCriteria());
}

QJsonArray Tag::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<TagObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<TagObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Tag(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Tag::modelData()
{
    return d.data();
}

const TModelObject *Tag::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Tag &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Tag &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Tag)
