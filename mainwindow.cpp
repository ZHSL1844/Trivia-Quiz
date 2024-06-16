#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global_variables.h"

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
    ui->categoryLine->setText(category);
    ui->difficultyLine->setText(difficulty);
    ui->question1->setText(question1);
    ui->question2->setText(question2);
    ui->question3->setText(question3);
    ui->choices1->setText(choices1);
    ui->choices2->setText(choices2);
    ui->choices3->setText(choices3);
}

