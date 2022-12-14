#include "headers/Calendar.h"
#include "headers/MailSender.h"
#include "ui_Calendar.h"

Calendar::Calendar(Student *student, QVector<Exam *> exams, QWidget *parent)
    : QWidget(parent), ui(new Ui::Calendar), _schedule(exams), _loginWindow(new LoginPage), _examsOverviewWindow(new ExamsOverview()),
      _profileWindow(new Profile)


{
    ui->setupUi(this);
    _student = student;
    _loginWindow->setStudent(_student);
    _examsOverviewWindow->setStudent(_student);
    _profileWindow->setStudent(_student);
    connect(this, &Calendar::fillProfileSignal, _profileWindow, &Profile::fillSlot);
    connect(_examsOverviewWindow, &ExamsOverview::fillCalendarSignal, this, &Calendar::colorCells);

    colorCells();
}


Calendar::~Calendar()
{
    delete ui;
    delete _profileWindow;
    delete _examsOverviewWindow;
    delete _loginWindow;
    for (auto exam : _schedule) {
        delete exam;
    }
    delete _student;
}

LoginPage *Calendar::getLoginPage() const
{
    return _loginWindow;
}

void Calendar::colorCells()
{
    QTextCharFormat fmt;
    fmt.setBackground(QColorConstants::Transparent);
    QMap<QDate, QTextCharFormat> dates = ui->calendarWidget->dateTextFormat();
    QList<QDate> keys                  = dates.keys();

    for (auto &key : keys) {
        ui->calendarWidget->setDateTextFormat(key, fmt);
    }

    _schedule = Utils::readJsonExamsFromFile("/output/schedule.json");
    fmt.setBackground(QColor(61, 66, 107));

    QTextCharFormat fmt2;
    fmt2.setBackground(QColor(255, 153, 51));

    for (auto &exam : _schedule) {
        QDate date     = exam->getDate();
        QDate oralDate = exam->getDateOral();
        ui->calendarWidget->setDateTextFormat(date, fmt);
        ui->calendarWidget->setDateTextFormat(oralDate, fmt2);
    }
}


QVector<QPair<QString, QString>> Calendar::checkResults()
{
    QVector<QPair<QString, QString>> changedExams;
    for (auto &exam : _schedule) {
        if (exam->checkIfDatePassed()) {
            QString url = exam->getUrl();
            if (url.isEmpty()) {
                qDebug() << "CALENDAR::CHECK RESULTS::Empty url string";
            } else {
                Request req;
                req.download(url);
                if (req.isFileChanged()) {
                    changedExams.push_back(QPair<QString, QString>(exam->getSubject().getName(), exam->getUrl()));
                    qDebug() << "Web page is updated!";
                }
            }
        }
    }

    return changedExams;
}

void Calendar::on_pbNewExam_clicked()
{

    _examsOverviewWindow->show();
}

void Calendar::on_pbCheckUrl_clicked()
{
    bool hasChanged                               = false;
    QVector<QPair<QString, QString>> changedExams = checkResults();
    for (auto &exam : changedExams) {
        QMessageBox msgBox;
        msgBox.setTextFormat(Qt::RichText);
        QMessageBox::information(&msgBox, "Rezultat provere",
                                 "Doslo je do promene na sajtu predmeta <a href='" + exam.second + "'>" + exam.first + "</a>");
        hasChanged = true;
    }

    if (!hasChanged) {
        QMessageBox::information(this, "Rezultat provere", "Nema promena na web stranicama.");
    }
}


void Calendar::on_pbSendMail_clicked()
{

    QDir dir("../MatfPlaner/output");
    QFile mailFile(dir.absoluteFilePath("mail.txt"));
    if (mailFile.open(QFile::WriteOnly)) {
        QString content = "RASPORED ISPITA:\n\n";
        for (auto &exam : _schedule) {
            content = content.append(exam->toString() + "\n");
        }
        mailFile.write(content.toUtf8());
        mailFile.close();
    } else {
        QMessageBox::warning(this, "Email", "Otvaranje fajla za slanje nije uspelo.");
        return;
    }

    MailSender ms;
    QString recip = _student->getEmail();
    auto res      = ms.send(recip);

    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res);
        QMessageBox::warning(this, "Email", "Slanje rasporeda nije uspelo.");
    } else
        QMessageBox::information(this, "Email", "Raspored je poslat!");
}


void Calendar::on_pbLogin_clicked()
{
    _loginWindow->show();
}


void Calendar::on_pbProfile_clicked()
{
    emit fillProfileSignal();
    _profileWindow->show();
}


void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    QString info;
    for (auto &exam : _schedule) {
        if (date == exam->getDate()) {
            info += exam->getSubject().getName() + "   " + exam->getTime().toString() + "\n";
        }
        if (date == exam->getDateOral()) {
            info += "Usmeni ispit: " + exam->getSubject().getName() + "   " + exam->getTimeOral().toString() + "\n";
        }
    }
    QMessageBox::information(this, "Ispit", info);
}

void Calendar::checkIfExamIsClose()
{
    QString closeExams = QString();
    QDate currentDate  = QDate::currentDate();
    for (auto exam : _schedule) {
        int daysToExam = currentDate.daysTo(exam->getDate());
        if (daysToExam <= 3) {
            if (daysToExam == 1) {
                closeExams.append("Ostao je ")
                    .append(QString::fromStdString(std::to_string(daysToExam)))
                    .append(" dan do ispita ")
                    .append(exam->getSubject().getName())
                    .append("\n");
            } else {
                closeExams.append("Ostalo je ")
                    .append(QString::fromStdString(std::to_string(daysToExam)))
                    .append(" dan do ispita ")
                    .append(exam->getSubject().getName())
                    .append("\n");
            }
        }
    }
    ui->notificationsTextEdit->setText(closeExams);
}
