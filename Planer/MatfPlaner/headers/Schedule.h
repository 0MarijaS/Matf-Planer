#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <algorithm>

#include "Exam.h"

class Schedule{

public:
    Schedule(QVector<Exam*> exams);
    void makeSchedule();
    ~Schedule();
    QVector<Exam*> getExams();

private:
    QVector<Exam*> _exams;
};

#endif // SCHEDULE_H
