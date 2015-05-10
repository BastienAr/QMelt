#pragma once
#include "common.h"
#include "matchresult.h"

// QT
#include <QObject>
#include <QSharedPointer>
#include <QVector>

M_NAMESPACE_DIFF_BEGIN

class MatchEngine : public QObject
{
    Q_OBJECT
public:
    explicit MatchEngine(QObject *parent = 0);

    QSharedPointer<MatchResult> match(
                                      QVector<QObject*>& leftObjects_,
                                      QVector<QObject*>& rightObjects_);

    double computeSimilarity(QObject* first_,
                             QObject* second_);

    QSharedPointer<QString> toString(QObject* object_);
signals:

public slots:
};


M_NAMESPACE_DIFF_END