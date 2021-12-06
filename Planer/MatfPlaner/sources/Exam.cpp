#include"headers/Utils.h"
#include "headers/Exam.hpp"


Exam::Exam(QDate date,QString url,Subject subject, bool passed, unsigned numbersOfTry)
{
    _date = date;
    _url = url;
    _subject = subject;
    _numbersOfTry = numbersOfTry;
}

Exam::Exam(QJsonObject obj){
       QString _dateString = obj.value("_date").toString();
        _date = Utils::fromQStringtoQDate(_dateString);
        _url = obj.value("_url").toString();
        QJsonObject subject =obj.value("_subject").toObject();
        _subject = Subject(subject);


}

void Exam::setPassed(){_passed = true;}
bool Exam::checkIfDatePassed(){
    if (_date < _date.currentDate())
        return true;

    return false;
}

bool Exam::checkIfDatePassed(QDate date){
    if (_date < date)
        return true;

    return false;
}


bool Exam::seeChangesInUrl(){
//vraca true ako je fajl promenjen
    Request req;
    req.download(_url);

    return req.isFileChanged();
}
