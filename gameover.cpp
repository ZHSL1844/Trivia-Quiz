#include "gameover.h"
#include "ui_gameover.h"
#include "oneplayer.h"
#include "global_variables.h"
#include <QString>

GameOver::GameOver(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOver)
{
    ui->setupUi(this);
    ui->label_score->setText("High Score: " + QString::number(score));
    score = 0;
}

GameOver::~GameOver()
{
    delete ui;
}
