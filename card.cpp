#include "card.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QApplication>
#include <math.h>
#include <QTime>
#include <QDir>
#include <QFile>
#include <QDebug>
Card::Card(QWidget *parent)
    : QPushButton(parent)
{
    corange=check("images/pt/classical/orange");
    cpurple=check("images/pt/classical/purple");
    cblue=check("images/pt/classical/blue");
    cwhite=check("images/pt/classical/white");
    gorange=check("images/pt/gvg/orange");
    gpurple=check("images/pt/gvg/purple");
    gblue=check("images/pt/gvg/blue");
    gwhite=check("images/pt/gvg/white");
    up=false;
    srand(QTime::currentTime().msec());

    str="images/back.png";
    pix.load(str,0,Qt::AvoidDither|Qt::ThresholdAlphaDither|Qt::ThresholdDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));
    connect(this,SIGNAL(clicked()),this,SLOT(work()));
}
void Card::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,str);
}

QString Card::roll()
{

    QString res="images/pt/gvg/";
    QStringList list;
    int pinzhi=qrand()%100;
    if(pinzhi==0)
     {
        res+="orange/";
        list=gorange;
    }
    else
        if(pinzhi<6)
        {
            res+="purple/";
            list=gpurple;
        }
        else if(pinzhi>79)
          {
            res+="blue/";
            list=gblue;
            }
            else
        {
            res+="white/";
            list=gwhite;
        }
    res+=list[qrand()%list.count()];
    return res;
}
QStringList Card::check(QString path)
{
      QStringList color;
      QDir dir(path);
      foreach (QFileInfo file,dir.entryInfoList(QDir::Files)) {
          color<<file.fileName();
      }
      return color;
}
void Card::work()
{
    if(!up)
    {
        QPixmap newcard;
        qDebug()<<"heeellllo";
        QString rrr=roll();
        qDebug()<<rrr;
        str=rrr;
        newcard.load(rrr,0,Qt::AvoidDither|Qt::ThresholdAlphaDither|Qt::ThresholdDither);
        resize(newcard.size());
        qDebug()<<newcard.size().height()<<newcard.size().width();
        setMask(newcard.mask());
        update();
        up=true;
    }
    else
    {
        str="images/back.png";
        pix.load(str,0,Qt::AvoidDither|Qt::ThresholdAlphaDither|Qt::ThresholdDither);
        resize(pix.size());
        setMask(QBitmap(pix.mask()));
        update();
        up=false;
    }
}
