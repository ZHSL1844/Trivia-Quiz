#include "mainwindow.h"
#include "global_variables.h"
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QPushButton>
#include <QPointer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    const QString &url = "https://opentdb.com/api.php?amount=3&category=27&difficulty=easy&type=multiple";
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://opentdb.com/api.php?amount=3&category=27&difficulty=easy&type=multiple"));

    QNetworkReply *reply = manager.get(request);

    QPointer<QNetworkReply> replyPtr(reply);

    QObject::connect(reply, &QNetworkReply::finished, [replyPtr](){
        if (replyPtr)
        {
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

                    if (i == 1)
                    {
                        category = questionObj["category"].toString();
                        difficulty = questionObj["difficulty"].toString();
                    //    question1 = question;
                     //   choices1 = choices.join(", ");
                    }

                    else if (i == 2)
                    {
                   //     question2 = question;
                   //     choices2 = choices.join(", ");
                    }

                    else
                    {
                      //  question3 = question;
                    //    choices3 = choices.join(", ");
                    }

                    i++;
                }
            } else {
                qDebug() << "Error: " << replyPtr->errorString();
            }
        }
        else
        {
            qDebug() << "wrong";
        }
    });

    //QObject::connect(ui->pushButton, SIGNAL(clicked()), &a,SLOT(fetchTriviaData()));

    return a.exec();
}
