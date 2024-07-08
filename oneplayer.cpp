#include "oneplayer.h"
#include "ui_oneplayer.h"
#include "global_variables.h"
#include "ui_mainwindow.h"
#include "gameover.h"
#include "ui_gameover.h"
#include <QApplication>
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
#include <QStringList>
#include <algorithm>
#include <random>
#include <QTimer>
#include <QMainWindow>
#include <random>
#include <iostream>

OnePlayer::OnePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OnePlayer)
    ,player_score(0)
    ,incorrect(0)
    ,timer(new QTimer(this))
    ,timeLeft(15)
{
    ui->setupUi(this);

    player_score = 0;
    questionIndex = 0;
    fetchQuestions();

    connect(timer, &QTimer::timeout, this, &OnePlayer::updateTimer);
}

void OnePlayer::fetchQuestions()
{
    std::random_device rd1;
    std::mt19937 generator(rd1());
    std::uniform_int_distribution<int> distribution(9, 32);
    int random = distribution(generator);
    c = QString::number(random);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(
        QUrl(QString("https://opentdb.com/api.php?amount=1&category=%1&difficulty=%2&type=multiple")
                 .arg(c)
                 .arg(d)));
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);
            QJsonObject obj = doc.object();
            questions = obj["results"].toArray();
            displayNextQuestion();
        } else {
            qDebug() << "Error fetching questions: " << reply->errorString();
        }
        reply->deleteLater();
    });
}

void OnePlayer::displayNextQuestion()
{
    if (incorrect < 3)
    {
        QJsonObject questionObj = questions[0].toObject();
        category = questionObj["category"].toString();
        ui->textEdit->setText("category: " + category);
        QString question = questionObj["question"].toString();
        ui->textBrowser->setText(question);

        QJsonArray incorrectAnswers = questionObj["incorrect_answers"].toArray();
        choices.clear();
        for (const auto &answer : incorrectAnswers) {
            choices.append(answer.toString());
        }
        correctAnswer = questionObj["correct_answer"].toString();
        choices.append(correctAnswer);

        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(choices.begin(), choices.end(), generator);

        ui->radioButton->setText(choices[0]);
        ui->radioButton_2->setText(choices[1]);
        ui->radioButton_3->setText(choices[2]);
        ui->radioButton_4->setText(choices[3]);
        questionIndex++;
        timeLeft = 15;
        ui->label_timer->setText("Time: " + QString::number(timeLeft));
        timer->start(1000);

        ui->label_score->setText("High Score: " + QString::number(player_score));
        ui->label_incorrect->setText("incorrect: " + QString::number(incorrect));
        fetchQuestions();
     }
    else
    {
        score = player_score;
        GameOver *g = new GameOver();
        g->show();
    }
}

void OnePlayer::updateTimer()
{
    timeLeft--;
    ui->label_timer->setText("Time: " + QString::number(timeLeft));
    if (timeLeft == 0) {
        timer->stop();
        checkAnswer("");
        fetchQuestions();
    }
}

void OnePlayer::checkAnswer(QString answer)
{
    if (answer == correctAnswer) {
        player_score++;
    }
    else
        incorrect++;
    fetchQuestions();
}

void OnePlayer::on_radioButton_clicked()
{
    timer->stop();
    checkAnswer(ui->radioButton->text());
}
void OnePlayer::on_radioButton_2_clicked()
{
    timer->stop();
    checkAnswer(ui->radioButton_2->text());
}
void OnePlayer::on_radioButton_3_clicked()
{
    timer->stop();
    checkAnswer(ui->radioButton_3->text());
}
void OnePlayer::on_radioButton_4_clicked()
{
    timer->stop();
    checkAnswer(ui->radioButton_4->text());
}
OnePlayer::~OnePlayer()
{
    delete ui;
}
