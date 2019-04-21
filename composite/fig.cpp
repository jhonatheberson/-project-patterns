#include "fig.h"
#include "ui_fig.h"
#include <QMessageBox>
#include <QPainter>
#include <QPen>


fig::fig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fig),
    ImgO(1151,621),
    ImgL(1151,621),
    ImgQ(1151,621),
    ImgT(1151,621),
    NumX("-"),
    NumO("-")
    {
    ui->setupUi(this);
    ui->comboBox->addItem("Ponto");
    ui->comboBox->addItem("Triangulo");
    ui->comboBox->addItem("Quadrado");
    ui->comboBox->addItem("Linha");

    QPainter painter;
    QColor corDeFundo(255,255,200);

    // Criando o Ponto
    ImgO.fill(corDeFundo);
    ponto();

    // Criando a Linha
    ImgL.fill(corDeFundo);
    line();

    // Criando o Quadrado
    ImgQ.fill(corDeFundo);
    quadrado();

    // Criando Triangulo
    ImgT.fill(corDeFundo);
    triangulo();
}



fig::~fig()
{
    delete ui;
}


void fig::ponto()
{
    QPen pen;
    QPainter painter;

    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.begin(&ImgO);
    painter.setPen(pen);
    painter.drawPoint(575,310);
    painter.end();
}
void fig::line()
{
    QPen pen;
    QPainter painter;

    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.begin(&ImgL);
    painter.setPen(pen);
    for(int i=20; i<1000; i++)
    {
        painter.drawPoint(75+i,310);
    }
    painter.end();
}
void fig::triangulo()//xmin=75, xmax=1075, ymin=560
{
    QPen pen;
    QPainter painter;

    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.begin(&ImgT);
    painter.setPen(pen);
    for(int i=0; i<1000; i++)
    {
        painter.drawPoint(75+i,560);
        if(i<500)
        {
            painter.drawPoint(75+i,560-i);
            painter.drawPoint(1075-i,560-i);
        }
    }

    painter.end();
}

void fig::quadrado()//int xmin=325, int ymin=560, int xmax=825, int ymax=60
{
    QPen pen;
    QPainter painter;

    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter.begin(&ImgQ);
    painter.setPen(pen);
    for(int i=0; i<500; i++)
    {
        painter.drawPoint(325+i,560);
        painter.drawPoint(325+i,60);
        painter.drawPoint(325,560-i);
        painter.drawPoint(825,60+i);
    }

    painter.end();
}

void fig::exibirFig()
{
    QString arg1 = ui->comboBox->currentText();

        if(arg1=="Ponto"){
            ui->img->setPixmap(ImgO);
        }
        else if(arg1=="Triangulo"){
            ui->img->setPixmap(ImgT);
        }
        else if(arg1=="Quadrado"){
            ui->img->setPixmap(ImgQ);
        }
        else if(arg1=="Linha"){
            ui->img->setPixmap(ImgL);
        }
}

void fig::on_Desenhar_clicked()
{
    exibirFig();
}

void fig::on_actionSair_triggered()
{
     QCoreApplication::quit();
}

void fig::on_actionAjuda_triggered()
{
      help.show();
}


