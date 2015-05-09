// ABLETON
#include "src/ableton/alsableton.h"
#include "src/ableton/alsliveset.h"

// IO
#include "src/io/alsfilesystem.h"

// TEST
#include "src/test/melttestcore.h"

// DIFF
#include "src/diff/stringcomparator.h"
#include "src/diff/depthfirsttraversal.h"
#include "src/diff/matchengine.h"

// QT
#include <QSharedPointer>
#include <QString>
#include <QDebug>

#if defined (Q_OS_WIN)
#define M_EXAMPLE_DIR "../Example/"
#elif defined (Q_OS_OSX)
#define M_EXAMPLE_DIR "../../../../Example/"
#endif


#define M_PATH_ALS_KENYA QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_01.xml")
#define M_PATH_ALS_KENYA_OUTPUT QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_01_output.xml")
#define M_PATH_ALS_ELATION QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_02.xml")
#define M_PATH_ALS_EMPTY QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_03.xml")
#define M_PATH_ALS_EMPTY2 QString(M_EXAMPLE_DIR) + QString("als-xml/sample_project_04.xml")


M_NAMESPACE_TEST_BEGIN


void MeltTestCore::testParser()
{
  QString filePath(M_PATH_ALS_KENYA);
  QSharedPointer<ableton::AlsAbleton> ableton;
  io::AlsFilesystem::load(filePath, ableton);
  io::AlsFilesystem::save(QString(M_PATH_ALS_KENYA_OUTPUT), ableton);
}

void MeltTestCore::testStringComparator()
{
  diff::StringComparator sc;
  QString* first = new QString("This is a short bit of text for testing purposes.");
  QString* second = new QString("This is another short bit of text for testing purposes.");
  QString* third = new QString("Very different from the previous test inputs.");
  QSharedPointer<QString> firstPointer = QSharedPointer<QString>(first);
  QSharedPointer<QString> secondPointer = QSharedPointer<QString>(second);
  QSharedPointer<QString> thirdPointer = QSharedPointer<QString>(third);

  double similarity = sc.computeSimilarity(firstPointer, secondPointer);
  qDebug() << similarity;

  similarity = sc.computeSimilarity(firstPointer, thirdPointer);
  qDebug() << similarity;
}

void MeltTestCore::testDepthFirstTraversal() {
  QString filePath(M_PATH_ALS_EMPTY);
  QSharedPointer<ableton::AlsAbleton> ableton_;
  io::AlsFilesystem::load(filePath, ableton_);
  diff::DepthFirstTraversal dft;
  QSharedPointer<QObject> qObjectPointer (ableton_->LiveSet.staticCast<QObject>());
  QVector<QObject*> objects (dft.traverse(qObjectPointer.data()));
  diff::MatchEngine me;
  for (auto something : objects)
  {
      qDebug() << *me.toString(something);
  }
}

void MeltTestCore::testQObjectToString() {
  QString filePath(M_PATH_ALS_EMPTY);
  QSharedPointer<ableton::AlsAbleton> ableton_;
  io::AlsFilesystem::load(filePath, ableton_);
  QSharedPointer<QObject> qObjectPointer (ableton_->LiveSet->Tracks[0].staticCast<QObject>());

  diff::MatchEngine me;
  QSharedPointer<QString> result = me.toString(qObjectPointer.data());
  qDebug() << *result.data();
}

M_NAMESPACE_TEST_END
