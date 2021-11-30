#ifndef THIRDYEARI_H
#define THIRDYEARI_H

#include <QMainWindow>
#include "headers/FourthYearI.h"


namespace Ui {
class ThirdYearI;
}

class ThirdYearI : public QMainWindow
{
    Q_OBJECT

signals:
    void backSignal();
public:
    explicit ThirdYearI(QWidget *parent = nullptr);
    ~ThirdYearI();

private slots:
    void on_pbBack_clicked();

    void on_pbNext_clicked();

    void on_pbEnd_clicked();

private:
    Ui::ThirdYearI *ui;
    FourthYearI *fourthWindow;
};

#endif // THIRDYEARI_H