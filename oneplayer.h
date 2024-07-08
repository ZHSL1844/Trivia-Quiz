#ifndef ONEPLAYER_H
#define ONEPLAYER_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>

namespace Ui {
class OnePlayer;
}

class OnePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit OnePlayer(QWidget *parent = nullptr);
    ~OnePlayer();
    void displayNextQuestion(const QJsonArray &results);

private slots:
    void fetchQuestions();
    void displayNextQuestion();
    void updateTimer();
    void checkAnswer(QString answer);

    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();

private:
    Ui::OnePlayer *ui;
    int incorrect;
    QTimer *timer;
    int timeLeft;
    QString correctAnswer;
    QStringList choices;
    QJsonArray questions;
    // QString c;
    // QString d;
public:
        int player_score;
};

#endif // ONEPLAYER_H
