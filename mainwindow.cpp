#include "mainwindow.h"
#include <QComboBox>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPointer>
#include <QPushButton>
#include <QRadioButton>
#include <QtCleanUpFunction>
#include "global_variables.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox_cat->addItem("general knowledge");
    ui->comboBox_cat->addItem("book");
    ui->comboBox_cat->addItem("film");
    ui->comboBox_cat->addItem("music");
    ui->comboBox_cat->addItem("musicals & theaters");
    ui->comboBox_cat->addItem("television");
    ui->comboBox_cat->addItem("video games");
    ui->comboBox_cat->addItem("board games");
    ui->comboBox_cat->addItem("art");
    ui->comboBox_cat->addItem("animals");
    ui->comboBox_cat->addItem("comics");
    ui->comboBox_cat->addItem("anime & manga");
    ui->comboBox_cat->addItem("science & nature");
    ui->comboBox_cat->addItem("computers");
    ui->comboBox_cat->addItem("mathematics");
    ui->comboBox_cat->addItem("mythology");
    ui->comboBox_cat->addItem("sports");
    ui->comboBox_cat->addItem("geography");
    ui->comboBox_cat->addItem("history");
    ui->comboBox_cat->addItem("politics");
    ui->comboBox_cat->addItem("celebrities");
    ui->comboBox_cat->addItem("vehicles");
    ui->comboBox_cat->addItem("gadgets");
    ui->comboBox_cat->addItem("carton & animations");

    ui->comboBox_dif->addItem("hard");
    ui->comboBox_dif->addItem("medium");
    ui->comboBox_dif->addItem("easy");

    QObject::connect(ui->comboBox_cat, SIGNAL(currentIndexChanged(int)), this, SLOT(set_c()));

    QObject::connect(ui->comboBox_dif, SIGNAL(currentIndexChanged(int)), this, SLOT(set_d()));

    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushButton_clicked()));
}

void MainWindow::set_c()
{
    int index = ui->comboBox_cat->currentIndex();
    qDebug() << index;
    switch (index) {
    case 0:
        c = "10";
        break;
    case 1:
        c = "32";
        break;
    case 2:
        c = "12";
        break;
    case 3:
        c = "9";
        break;
    case 4:
        c = "13";
        break;
    case 5:
        c = "11";
        break;
    case 6:
        c = "14";
        break;
    case 7:
        c = "15";
        break;
    case 8:
        c = "16";
        break;
    case 9:
        c = "25";
        break;
    case 10:
        c = "27";
        break;
    case 11:
        c = "29";
        break;
    case 12:
        c = "31";
        break;
    case 13:
        c = "17";
        break;
    case 14:
        c = "18";
        break;
    case 15:
        c = "19";
        break;
    case 16:
        c = "20";
        break;
    case 17:
        c = "21";
        break;
    case 18:
        c = "22";
        break;
    case 19:
        c = "23";
        break;
    case 20:
        c = "24";
        break;
    case 21:
        c = "26";
        break;
    case 22:
        c = "28";
        break;
    case 23:
        c = "29";
    }
    qDebug() << c;
}

void MainWindow::set_d()
{
    int index = ui->comboBox_dif->currentIndex();
    qDebug() << index;
    switch (index) {
    case 0:
        d = "hard";
        break;
    case 1:
        d = "medium";
        break;
    case 2:
        d = "easy";
        break;
    }
}

void MainWindow::pushButton_clicked()
{
    qDebug() << "hello";
    QNetworkAccessManager manager;
    QNetworkRequest request(
        QUrl(QString("https://opentdb.com/api.php?amount=5&category=%1&difficulty=%2&type=multiple")
                 .arg(c)
                 .arg(d)));

    QNetworkReply *reply = manager.get(request);

    QPointer<QNetworkReply> replyPtr(reply);
    if (replyPtr)
        qDebug() << "yes";

    QObject::connect(reply, &QNetworkReply::finished, [this, replyPtr]() {
        if (replyPtr) {
            qDebug() << "bye";
            if (replyPtr->error() == QNetworkReply::NoError) {
                QByteArray data = replyPtr->readAll();
                QJsonDocument doc = QJsonDocument::fromJson(data);
                QJsonObject jsonObj = doc.object();
                QJsonArray results = jsonObj["results"].toArray();

                int i = 1;
                for (const auto &result : results) {
                    QJsonObject questionObj = result.toObject();
                    QString question = questionObj["question"].toString();

                    QJsonArray incorrectAnswers = questionObj["incorrect_answers"].toArray();
                    QStringList choices;
                    for (const auto &answer : incorrectAnswers) {
                        choices.append(answer.toString());
                    }
                    choices.append(questionObj["correct_answer"].toString());

                    if (i == 1) {
                        category = questionObj["category"].toString();
                        qDebug() << category;
                        difficulty = questionObj["difficulty"].toString();
                        //    question1 = question;
                        //   choices1 = choices.join(", ");
                    }

                    else if (i == 2) {
                        //     question2 = question;
                        //     choices2 = choices.join(", ");
                    }

                    else {
                        //  question3 = question;
                        //    choices3 = choices.join(", ");
                    }

                    i++;
                }
            } else {
                qDebug() << "Error: " << replyPtr->errorString();
            }
        } else {
            qDebug() << "wrong";
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
