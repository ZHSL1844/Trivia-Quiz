#ifndef TWOPLAYER_H
#define TWOPLAYER_H

#include <QWidget>

namespace Ui {
class TwoPlayer;
}

class TwoPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit TwoPlayer(QWidget *parent = nullptr);
    ~TwoPlayer();

private:
    Ui::TwoPlayer *ui;
};

#endif // TWOPLAYER_H
