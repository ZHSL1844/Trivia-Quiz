#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QButtonGroup>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = nullptr);

private :
    QButtonGroup *buttonGroup;
};

#endif // MYWIDGET_H
