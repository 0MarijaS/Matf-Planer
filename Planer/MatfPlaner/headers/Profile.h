#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include "headers/Student.h"

namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();
    void setStudent(Student* s);

public slots:
    void fillSlot();
private:
    Ui::Profile *ui;
    Student* _student;
};

#endif // PROFILE_H
