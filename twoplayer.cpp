#include "twoplayer.h"
#include "ui_twoplayer.h"

TwoPlayer::TwoPlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TwoPlayer)
{
    ui->setupUi(this);
}

TwoPlayer::~TwoPlayer()
{
    delete ui;
}
