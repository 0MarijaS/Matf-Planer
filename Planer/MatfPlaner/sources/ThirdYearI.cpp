#include "headers/ThirdYearI.h"
#include "ui_ThirdYearI.h"

ThirdYearI::ThirdYearI(QWidget *parent) :
    QMainWindow(parent),
    _student(new Student),
    ui(new Ui::ThirdYearI),
    fourthWindow(new FourthYearI)
{
    ui->setupUi(this);
    connect(fourthWindow, &FourthYearI::backSignal, this, &QWidget::show);
}


ThirdYearI::~ThirdYearI()
{
    delete ui;
}


void ThirdYearI::on_pbBack_clicked()
{
    emit backSignal();
    hide();
}


void ThirdYearI::on_pbNext_clicked()
{
    fourthWindow->setStudent(_student);
    fourthWindow->show();
    hide();
    //nzm dal ovde curi memorija
}


void ThirdYearI::on_pbEnd_clicked()
{
    hide();
}

void ThirdYearI::setStudent(Student* student){
    _student = student;
}
