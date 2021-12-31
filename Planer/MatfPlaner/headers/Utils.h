#ifndef UTILS_H
#define UTILS_H
#include "headers/InsertExams.h"
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>

class Utils : public QObject
{
    Q_OBJECT
public:
    Utils();

    static QVector<Exam*> readJsonExamsFromFile(const QString &filename);
    static QVector<Subject*> readJsonSubjectsFromFile(QString fileName);
    static QByteArray readJsonFromFile(QString &fileName);
    static void writeJsonExamsToFile(QString filePath, const QVector<Exam*>& exams);

};

#endif // UTILS_H
