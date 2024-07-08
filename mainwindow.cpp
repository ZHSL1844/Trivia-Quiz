#include "mainwindow.h"
#include <QMessageBox>
#include "global_variables.h"
#include "ui_mainwindow.h"
#include <QRadioButton>
#include <QPushButton>
#include <QComboBox>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPointer>
#include <QPushButton>
#include <QStringList>
#include <random>
#include <algorithm>
#include <QRadioButton>

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

    ui->comboBox_dif->addItem("easy");
    ui->comboBox_dif->addItem("medium");
    ui->comboBox_dif->addItem("hard");

    QObject::connect(ui->comboBox_cat, SIGNAL(currentIndexChanged(int)), this, SLOT(set_c()));

    QObject::connect(ui->comboBox_dif, SIGNAL(currentIndexChanged(int)), this, SLOT(set_d()));


    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QNetworkRequest request(QUrl(QString("https://opentdb.com/api.php?amount=5&category=%1&difficulty=%2&type=multiple").arg(c).arg(d)));
        QNetworkReply *reply = manager->get(request);

        connect(reply, &QNetworkReply::finished, this, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray data = reply->readAll();
                QJsonDocument doc = QJsonDocument::fromJson(data);
                QJsonObject obj = doc.object();
                QJsonArray results = obj["results"].toArray();
                int i = 1;
                for (const auto &result : results) {
                    QJsonObject questionObj = result.toObject();
                    QString question = questionObj["question"].toString();
                    category = questionObj["category"].toString();
                    qDebug() << "categoryyyyyyyyyyyyyyy:"<< category;
                    ui->textBrowser->setText(question);

                    QJsonArray incorrectAnswers = questionObj["incorrect_answers"].toArray();
                    QStringList choices;
                    for (const auto &answer : incorrectAnswers)
                    {
                        choices.append(answer.toString());
                    }
                    correctAnswer = questionObj["correct_answer"].toString();
                    choices.append(correctAnswer);

                    //Randomize the order of the list
                    std::random_device rd;
                    std::mt19937 generator(rd());
                    std::shuffle(choices.begin(), choices.end(), generator);

                    ui->label_1->setText(choices[0]);
                    ui->label_2->setText(choices[1]);
                    ui->label_3->setText(choices[2]);
                    ui->label_4->setText(choices[3]);
                    connect(ui->radioButton, &QRadioButton::clicked, this, [=](){
                        if (ui->label_1->text() == correctAnswer)
                            score++;
                        qDebug() << score;
                    });
                    connect(ui->radioButton_2, &QRadioButton::clicked, this, [=](){
                        if (ui->label_2->text() == correctAnswer)
                            score++;
                        qDebug() << score;
                    });
                    connect(ui->radioButton_3, &QRadioButton::clicked, this, [=](){
                        if (ui->label_3->text() == correctAnswer)
                            score++;
                        qDebug() << score;
                    });
                    connect(ui->radioButton_4, &QRadioButton::clicked, this, [=](){
                        if (ui->label_4->text() == correctAnswer)
                            score++;
                        qDebug() << score;
                    });

                }
            } else {
                qDebug() << "Error fetching questions: " << reply->errorString();
            }

            reply->deleteLater();
        });
    });

}

void MainWindow::set_c()
{
    int index = ui->comboBox_cat->currentIndex();
    qDebug() << index;
    switch (index) {
    case 0:
        c = "9";
        break;
    case 1:
        c = "10";
        break;
    case 2:
        c = "11";
        break;
    case 3:
        c = "12";
        break;
    case 4:
        c = "13";
        break;
    case 5:
        c = "14";
        break;
    case 6:
        c = "15";
        break;
    case 7:
        c = "16";
        break;
    case 8:
        c = "25";
        break;
    case 9:
        c = "27";
        break;
    case 10:
        c = "29";
        break;
    case 11:
        c = "31";
        break;
    case 12:
        c = "17";
        break;
    case 13:
        c = "18";
        break;
    case 14:
        c = "19";
        break;
    case 15:
        c = "20";
        break;
    case 16:
        c = "21";
        break;
    case 17:
        c = "22";
        break;
    case 18:
        c = "23";
        break;
    case 19:
        c = "24";
        break;
    case 20:
        c = "26";
        break;
    case 21:
        c = "28";
        break;
    case 22:
        c = "30";
        break;
    case 23:
        c = "32";
    }
    qDebug() << c;
}

void MainWindow::set_d()
{
    int index = ui->comboBox_dif->currentIndex();
    //  qDebug() << index;
    switch (index)
    {
    case 0:
        d="easy"; break;
    case 1:
        d="medium"; break;
    case 2:
        d="hard"; break;
    }
}

// void MainWindow::trivia()
// {
//     qDebug() << "hello";
//     QNetworkAccessManager manager;
//     QNetworkRequest request(
//         QUrl(QString("https://opentdb.com/api.php?amount=5&category=%1&difficulty=%2&type=multiple").arg(c).arg(d)));

//     QNetworkReply *reply = manager.get(request);

//     QPointer<QNetworkReply> replyPtr(reply);
//     if (replyPtr)
//         qDebug() << "yes";

//        QObject::connect(reply, &QNetworkReply::finished, [replyPtr]() {
//     if (replyPtr) {
//         qDebug() << "bye";
//         if (replyPtr->error() == QNetworkReply::NoError) {
//         QByteArray data = replyPtr->readAll();
//         QJsonDocument doc = QJsonDocument::fromJson(data);
//         QJsonObject jsonObj = doc.object();
//         QJsonArray results = jsonObj["results"].toArray();

//         int i = 1;
//         for (const auto &result : results) {
//             QJsonObject questionObj = result.toObject();
//             // QString question = questionObj["question"].toString();

//             QJsonArray incorrectAnswers = questionObj["incorrect_answers"].toArray();
//             QStringList choices;
//             for (const auto &answer : incorrectAnswers) {
//                 choices.append(answer.toString());
//             }
//             choices.append(questionObj["correct_answer"].toString());

//             if (i == 1) {
//                 category = questionObj["category"].toString();
//                 qDebug() << category;
//                 difficulty = questionObj["difficulty"].toString();
//                 //    question1 = question;
//                 //   choices1 = choices.join(", ");
//             }

//             else if (i == 2) {
//                 //     question2 = question;
//                 //     choices2 = choices.join(", ");
//             }

//             else {
//                 //  question3 = question;
//                 //    choices3 = choices.join(", ");
//             }

//             i++;
//         }
//         } else {
//         qDebug() << "Error: " << replyPtr->errorString();
//          }
//     } else {
//         qDebug() << "wrong";
//     }
//         });
// }


MainWindow::~MainWindow()
{
    delete ui;
}
