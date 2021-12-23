#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "headers/FirstYearI.h"
#include "headers/FirstYearM.h"
#include "headers/Window.h"
#include <QRegularExpression>

namespace Ui {
class LoginPage;
}

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    void setStudent(Student* student);
    ~LoginPage();

private slots:
    void on_nextButton_clicked();

private:
    Ui::LoginPage *ui;
    Student* _student;
    FirstYearM* _mWindow;
    FirstYearI* _iWindow;
    Window* window;
};

#endif // LOGINPAGE_H
