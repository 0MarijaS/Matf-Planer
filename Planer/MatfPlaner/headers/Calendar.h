#ifndef CALENDAR_H
#define CALENDAR_H
#include"headers/Exam.hpp"
#include <QWidget>
#include "headers/LoginPage.h"

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    explicit Calendar( QList<Exam*> exams = {}, QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_pbNewExam_clicked();

    void on_pbProfile_clicked();

private:
    Ui::Calendar *ui;
    LoginPage *loginWindow;
    QList<Exam*> _exams;
};

#endif // CALENDAR_H
