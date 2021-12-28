#include <QApplication>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QVector>
#include "headers/Calendar.h"
#include "headers/Student.h"
#include "headers/Utils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir targetDir("../MatfPlaner/resources");
    QString examsPath = targetDir.absolutePath() + "/exams.json";
    QString stylePath = targetDir.absolutePath() + "/style.qss";

    QFile file(stylePath);
    if(file.open(QFile::ReadOnly) == file.error()){
        qDebug()<<file.errorString();
    }
    else{
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
    }

    QVector<Exam*> exams = Utils::readJsonExamsFromFile(examsPath);
    Student *student = new Student();
    student->readFromJson();
    if(student->getName().compare("")==0){
        Calendar w = Calendar(student,exams);
        w.show();
        w.getLoginPage()->show();
        return a.exec();
    }else{
        Calendar w = Calendar(student,exams);
        w.show();
        return a.exec();
    }
}
