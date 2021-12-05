#include "headers/Subject.hpp"
#include <QApplication>
#include<QList>
#include<QFile>
#include<QJsonDocument>
#include <QJsonArray>
#include"headers/Exam.hpp"
#include "headers/Calendar.h"
#include "headers/Student.hpp"
#include "headers/Utils.h"
int main(int argc, char *argv[])
{   const QString JSON_FILE= "C:\\Users\\saram\\Desktop\\MatfPlaner\\15-Matf-Planer\\Planer\\MatfPlaner\\resources\\exams.json";
    QApplication a(argc, argv);
    QList<Exam*> exams = Utils::readJsonObjectsFromFile(JSON_FILE);
    if(exams.isEmpty()){
        LoginPage lp;
        lp.show();
        return a.exec();
    } else {
        Calendar w = Calendar(exams);
        w.show();
        return a.exec();
    }
    return a.exec();
}
