#include "mainwindow.h"
#include "oneplayer.h"
#include "global_variables.h"
#include "ui_mainwindow.h"
#include "twoplayer.h"
#include <QComboBox>
#include <QPushButton>

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

    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(set()));

    QObject::connect(ui->comboBox_cat, SIGNAL(currentIndexChanged(int)), this, SLOT(set_c()));

    QObject::connect(ui->comboBox_dif, SIGNAL(currentIndexChanged(int)), this, SLOT(set_d()));
}

void MainWindow::set_c()
{
    if (mode == 1)
    {
    int index = ui->comboBox_cat->currentIndex();
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
    }
}

void MainWindow::set_d()
{
    int index = ui->comboBox_dif->currentIndex();
    switch (index) {
    case 0:
        d = "easy";
        break;
    case 1:
        d = "medium";
        break;
    case 2:
        d = "hard";
        break;
    }
}
void MainWindow::set()
{
    mode = ui->comboBox->currentIndex();
    if(mode == 0)
    {
    ui->comboBox_cat->hide();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (mode == 0)
    {
    OnePlayer *p = new OnePlayer();
    p->show();
    }
    else
    {
        TwoPlayer *t = new TwoPlayer();
        t->show();
    }
}

