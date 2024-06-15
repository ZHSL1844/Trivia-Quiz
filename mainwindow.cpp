#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "hello";
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://opentdb.com/api.php?amount=3&category=27&difficulty=easy&type=multiple"));

    QNetworkReply *reply = manager.get(request);

    QObject::connect(reply, &QNetworkReply::finished, [&](){
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "right";
            QByteArray data = reply->readAll();
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

                if (i == 1)
                {
                    qDebug() << "1";
                    QString category = questionObj["category"].toString();
                    ui->categoryLine->setText(category);
                    QString difficulty = questionObj["difficulty"].toString();
                    ui->difficultyLine->setText(difficulty);
                    ui->question1->setText(question);
                    ui->choices1->setText(choices.join(", "));
                }

                else if (i == 2)
                {
                    qDebug() << "2";
                    ui->question2->setText(question);
                    ui->choices2->setText(choices.join(", "));
                }

                else
                {
                    qDebug() << "3";
                    ui->question3->setText(question);
                    ui->choices3->setText(choices.join(", "));
                }

                i++;
            }
        } else {
            qDebug() << "Error: " << reply->errorString();
        }
        //    a.quit();
    });
    qDebug() << "bye";
}

