#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <QJsonObject>
#include <QString>
#include <iostream>

class Subject
{
  public:
    Subject(QString name, int espb);
    Subject();
    explicit Subject(const Subject *other);
    QJsonObject *toJson() const;
    explicit Subject(QJsonValue val);
    QString getName() const;
    int getEspb() const;

  private:
    int _espb;
    bool _passed;
    QString _name;
};

#endif
