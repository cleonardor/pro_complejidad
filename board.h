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

    int getN();
    int getAmountCities();
    QVector<City>* getCitiesRef();

private:
    int n;
    int amoutCities;
    QVector<City> cities;

    QPushButton *loadFileButton;
    QPushButton *seeFileButton;
    QPushButton *runButton;
    QPlainTextEdit *textEdit;

private slots:
        void loadFileSlot();

signals:
        void loadFileDoneSignal();
};

#endif // BOARD_H
