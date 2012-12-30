#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
QT_BEGIN_NAMESPACE
class QPushButton;
class City;
class QPlainTextEdit;
QT_END_NAMESPACE

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = 0);
    ~Board();

    int getM();
    int getAmountCities();
    QVector<City *>* getCitiesRef();

private:
    int m;
    int amountCities;
    QVector<City *> cities;

    QPushButton *loadFileButton;
    QPushButton *seeFileButton;
    QPushButton *runButton;
    QPlainTextEdit *textEdit;

    void clearCities();

private slots:
        void loadFileSlot();
        void runSlot();

signals:
        void loadFileDoneSignal();
        void runSignal();
};

#endif // BOARD_H
