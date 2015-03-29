#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QPushButton>
class Card : public QPushButton
{
    Q_OBJECT

public:
    Card(QWidget *parent = 0);
private slots:
    void work();
private:
    QString roll();
    QStringList check(QString path);
    void paintEvent(QPaintEvent *);
    bool up;
    QPixmap pix;
    QString str;
    QStringList corange;
    QStringList cpurple;
    QStringList cblue;
    QStringList cwhite;
    QStringList gorange;
    QStringList gpurple;
    QStringList gblue;
    QStringList gwhite;
};
#endif // CARD_H
