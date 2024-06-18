#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global_variables.h"
#include <QMessageBox>



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
    QString c,d;
    /*
    ui->categoryLine->setText(category);
    ui->difficultyLine->setText(difficulty);
    ui->question1->setText(question1);
    ui->question2->setText(question2);
    ui->question3->setText(question3);
    ui->choices1->setText(choices1);
    ui->choices2->setText(choices2);
    ui->choices3->setText(choices3);
*/
#include "MyWidget.h"
#include <QRadioButton>

    MyWidget::MyWidget(QWidget *parent)
        : QWidget(parent)
    {
/*
        // Create radio buttons
        QRadioButton *radio_book  = new QRadioButton("Book", this);
        QRadioButton *radio_cart  = new QRadioButton("carton & animations", this);
        QRadioButton *radio_music = new QRadioButton("Music", this);
        QRadioButton *radio_knw   = new QRadioButton("general knowledge", this);
        QRadioButton *radio_thea  = new QRadioButton("musicals & theaters", this);
        QRadioButton *radio_film  = new QRadioButton("film", this);
        QRadioButton *radio_telev = new QRadioButton("television", this);
        QRadioButton *radio_vg    = new QRadioButton("video games", this);
        QRadioButton *radio_bg    = new QRadioButton("board games", this);
        QRadioButton *radio_art   = new QRadioButton("art", this);
        QRadioButton *radio_anima = new QRadioButton("animals", this);
        QRadioButton *radio_comic = new QRadioButton("comics", this);
        QRadioButton *radio_manga = new QRadioButton("anime & manga", this);
        QRadioButton *radio_scien = new QRadioButton("science & nature", this);
        QRadioButton *radio_comp  = new QRadioButton("computers", this);
        QRadioButton *radio_math  = new QRadioButton("mathematics", this);
        QRadioButton *radio_myth  = new QRadioButton("mythology", this);
        QRadioButton *radio_sport = new QRadioButton("sports", this);
        QRadioButton *radio_geo   = new QRadioButton("geography", this);
        QRadioButton *radio_histo = new QRadioButton("history", this);
        QRadioButton *radio_polit = new QRadioButton("politics", this);
        QRadioButton *radio_celeb = new QRadioButton("celebrities", this);
        QRadioButton *radio_vehi  = new QRadioButton("vehicles", this);
        QRadioButton *radio_gadge = new QRadioButton("gadgets", this);


        // Create button group and assign IDs
        buttonGroup = new QButtonGroup(this);
        buttonGroup->addButton(radio_book, 0);
        buttonGroup->addButton(radio_cart, 1);
        buttonGroup->addButton(radio_music, 2);
        buttonGroup->addButton(radio_knw, 3);
        buttonGroup->addButton(radio_thea, 4);
        buttonGroup->addButton(radio_film, 5);
        buttonGroup->addButton(radio_telev, 6);
        buttonGroup->addButton(radio_vg, 7);
        buttonGroup->addButton(radio_bg, 8);
        buttonGroup->addButton(radio_art, 9);
        buttonGroup->addButton(radio_anima, 10);
        buttonGroup->addButton(radio_comic, 11);
        buttonGroup->addButton(radio_manga, 12);
        buttonGroup->addButton(radio_scien, 13);
        buttonGroup->addButton(radio_comp, 14);
        buttonGroup->addButton(radio_math, 15);
        buttonGroup->addButton(radio_myth, 16);
        buttonGroup->addButton(radio_sport, 17);
        buttonGroup->addButton(radio_geo, 18);
        buttonGroup->addButton(radio_histo, 19);
        buttonGroup->addButton(radio_polit, 20);
        buttonGroup->addButton(radio_celeb, 21);
        buttonGroup->addButton(radio_vehi, 22);
        buttonGroup->addButton(radio_gadge, 23);

     */
        buttonGroup = new QButtonGroup(this);
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

        // Connect signal for handling radio button selection
        connect(buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), [this](int id) {
            int c = -1; // Default value for 'c'
            switch (id)
            {
            case 0:
                c = 10;  break;
            case 1:
                c = 32;  break;
            case 2:
                c = 12; break;
            case 3:
                c=9; break;
            case 4:
                c=13; break;
            case 5:
                c=11; break;
            case 6:
                c=14; break;
            case 7:
                c=15; break;
            case 8:
                c=16;break;
            case 9:
                c=25; break;
            case 10:
                c=27; break;
            case 11:
                c=29; break;
            case 12:
                c=31; break;
            case 13:
                c=17; break;
            case 14:
                c=18; break;
            case 15:
                c=19; break;
            case 16:
                c=20; break;
            case 17:
                c=21; break;
            case 18:
                c=22; break;
            case 19:
                c=23; break;
            case 20:
                c=24; break;
            case 21:
                c=26; break;
            case 22:
                c=28; break;
            case 23:
                c=
            }
            // Use the value of 'c' as needed
        });
    }
}
