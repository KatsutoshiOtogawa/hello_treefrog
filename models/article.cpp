#include <TreeFrogModel>
#include "article.h"
#include "sqlobjects/articleobject.h"

Article::Article() :
    TAbstractModel(),
    d(new ArticleObject())
{
    // set the initial parameters
}

Article::Article(const Article &other) :
    TAbstractModel(),
    d(other.d)
{ }

Article::Article(const ArticleObject &object) :
    TAbstractModel(),
    d(new ArticleObject(object))
{ }

Article::~Article()
{
    // If the reference count becomes 0,
    // the shared data object 'ArticleObject' is deleted.
}

QString Article::id() const
{
    return d->id;
}

void Article::setId(const QString &id)
{
    d->id = id;
}

QString Article::title() const
{
    return d->title;
}

void Article::setTitle(const QString &title)
{
    d->title = title;
}

QString Article::body() const
{
    return d->body;
}

void Article::setBody(const QString &body)
{
    d->body = body;
}

QString Article::createdAt() const
{
    return d->created_at;
}

QString Article::updatedAt() const
{
    return d->updated_at;
}

int Article::lockRevision() const
{
    return d->lock_revision;
}

Article &Article::operator=(const Article &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Article Article::create(const QString &id, const QString &title, const QString &body)
{
    ArticleObject obj;
    obj.id = id;
    obj.title = title;
    obj.body = body;
    if (!obj.create()) {
        return Article();
    }
    return Article(obj);
}

Article Article::create(const QVariantMap &values)
{
    Article model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Article Article::get(const QString &id)
{
    TSqlORMapper<ArticleObject> mapper;
    return Article(mapper.findByPrimaryKey(id));
}

Article Article::get(const QString &id, int lockRevision)
{
    TSqlORMapper<ArticleObject> mapper;
    TCriteria cri;
    cri.add(ArticleObject::Id, id);
    cri.add(ArticleObject::LockRevision, lockRevision);
    return Article(mapper.findFirst(cri));
}

int Article::count()
{
    TSqlORMapper<ArticleObject> mapper;
    return mapper.findCount();
}

QList<Article> Article::getAll()
{
    return tfGetModelListByCriteria<Article, ArticleObject>(TCriteria());
}

QJsonArray Article::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ArticleObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ArticleObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Article(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Article::modelData()
{
    return d.data();
}

const TModelObject *Article::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Article &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Article &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Article)
