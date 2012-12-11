#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();

private:
    QPushButton *loadFileButton;
    QPushButton *seeFileButton;
    QPushButton *runButton;

private slots:
        void loadFileSlot();
};

#endif // BOARD_H
