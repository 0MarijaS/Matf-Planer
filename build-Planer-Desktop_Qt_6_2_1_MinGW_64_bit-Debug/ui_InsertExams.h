/********************************************************************************
** Form generated from reading UI file 'InsertExams.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTEXAMS_H
#define UI_INSERTEXAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertExams
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *examLabel;
    QLineEdit *examLineEdit;
    QLabel *dateLabel;
    QLineEdit *dateLineEdit;
    QLabel *urlLabel;
    QLineEdit *urlLineEdit;
    QPushButton *addExamButton;
    QPushButton *clearWidgetButton;
    QPushButton *endInputExamButton;

    void setupUi(QWidget *InsertExams)
    {
        if (InsertExams->objectName().isEmpty())
            InsertExams->setObjectName(QString::fromUtf8("InsertExams"));
        InsertExams->resize(330, 268);
        verticalLayout = new QVBoxLayout(InsertExams);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        examLabel = new QLabel(InsertExams);
        examLabel->setObjectName(QString::fromUtf8("examLabel"));

        verticalLayout->addWidget(examLabel);

        examLineEdit = new QLineEdit(InsertExams);
        examLineEdit->setObjectName(QString::fromUtf8("examLineEdit"));

        verticalLayout->addWidget(examLineEdit);

        dateLabel = new QLabel(InsertExams);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        verticalLayout->addWidget(dateLabel);

        dateLineEdit = new QLineEdit(InsertExams);
        dateLineEdit->setObjectName(QString::fromUtf8("dateLineEdit"));

        verticalLayout->addWidget(dateLineEdit);

        urlLabel = new QLabel(InsertExams);
        urlLabel->setObjectName(QString::fromUtf8("urlLabel"));

        verticalLayout->addWidget(urlLabel);

        urlLineEdit = new QLineEdit(InsertExams);
        urlLineEdit->setObjectName(QString::fromUtf8("urlLineEdit"));

        verticalLayout->addWidget(urlLineEdit);

        addExamButton = new QPushButton(InsertExams);
        addExamButton->setObjectName(QString::fromUtf8("addExamButton"));

        verticalLayout->addWidget(addExamButton);

        clearWidgetButton = new QPushButton(InsertExams);
        clearWidgetButton->setObjectName(QString::fromUtf8("clearWidgetButton"));

        verticalLayout->addWidget(clearWidgetButton);

        endInputExamButton = new QPushButton(InsertExams);
        endInputExamButton->setObjectName(QString::fromUtf8("endInputExamButton"));

        verticalLayout->addWidget(endInputExamButton);


        retranslateUi(InsertExams);

        QMetaObject::connectSlotsByName(InsertExams);
    } // setupUi

    void retranslateUi(QWidget *InsertExams)
    {
        InsertExams->setWindowTitle(QCoreApplication::translate("InsertExams", "Form", nullptr));
        examLabel->setText(QCoreApplication::translate("InsertExams", "predmet:", nullptr));
        dateLabel->setText(QCoreApplication::translate("InsertExams", "datum:", nullptr));
        urlLabel->setText(QCoreApplication::translate("InsertExams", "url do stranice asistenta:", nullptr));
        addExamButton->setText(QCoreApplication::translate("InsertExams", "dodaj ispit", nullptr));
        clearWidgetButton->setText(QCoreApplication::translate("InsertExams", "o\304\215isti prozor", nullptr));
        endInputExamButton->setText(QCoreApplication::translate("InsertExams", "zavr\305\241i unos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertExams: public Ui_InsertExams {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTEXAMS_H
