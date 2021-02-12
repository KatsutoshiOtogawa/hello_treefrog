#ifndef ARTICLE_H
#define ARTICLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ArticleObject;
class QJsonArray;


class T_MODEL_EXPORT Article : public TAbstractModel
{
public:
    Article();
    Article(const Article &other);
    Article(const ArticleObject &object);
    ~Article();

    QString id() const;
    void setId(const QString &id);
    QString title() const;
    void setTitle(const QString &title);
    QString body() const;
    void setBody(const QString &body);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Article &operator=(const Article &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Article create(const QString &id, const QString &title, const QString &body);
    static Article create(const QVariantMap &values);
    static Article get(const QString &id);
    static Article get(const QString &id, int lockRevision);
    static int count();
    static QList<Article> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ArticleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Article &model);
    friend QDataStream &operator>>(QDataStream &ds, Article &model);
};

Q_DECLARE_METATYPE(Article)
Q_DECLARE_METATYPE(QList<Article>)

#endif // ARTICLE_H
