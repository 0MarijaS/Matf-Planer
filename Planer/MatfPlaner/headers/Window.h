#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QWidget>
#include <QVector>

#include <QVBoxLayout>
#include <QCheckBox>
#include <QButtonGroup>
#include <QPushButton>
#include <QLabel>

#include "headers/Utils.h"
#include "headers/Student.h"


class Window : public QWidget
{
    Q_OBJECT

signals:
    void showLogin();
public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

    void setFilename(QString filename);
    void setStudent(Student* student);
    void setupWindow();

private:
    QString _filename;
    int year;

    Window *previousYear;
    Window *nextYear = nullptr;

    Student* _student;
    QVector<Subject*> _subjects;

    QVBoxLayout *verticalLayout;
    QButtonGroup *buttonGroup;

    QLabel *label;
    QLabel *infoLabel;
    QPushButton *nextButton;
    QPushButton *previousButton;

    QVector<QCheckBox*> checkBoxes;

    QString nameLabel();

private slots:
    void setupNextWindow();
    void setupPreviousWindow();
};

#endif // WINDOW_H
