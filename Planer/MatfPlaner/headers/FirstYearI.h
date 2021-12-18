#ifndef FIRSTYEARI_H
#define FIRSTYEARI_H

#include <QMainWindow>
#include "headers/SecondYearI.h"

namespace Ui {
class FirstYearI;
}

class FirstYearI : public QMainWindow
{
    Q_OBJECT

signals:
    void backSignal();
public:
    explicit FirstYearI(QWidget *parent = nullptr);
    ~FirstYearI();
    void setStudent(Student* student);

private slots:

    void on_pbBack_clicked();

    void on_pbNext_clicked();

    void on_pbEnd_clicked();

private:
    Ui::FirstYearI *ui;
    Student *_student;
    SecondYearI *secondWindow;

};

#endif // FIRSTYEARI_H
