#include "fig.h"
#include "ui_fig.h"
#include <QMessageBox>
#include <QPainter>
#include <QPen>


fig::fig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fig),
    ImgX(231, 191),
    ImgO(231, 191),
    NumX("-"),
    NumO("-")
    {
    ui->setupUi(this);
    ui->comboBox->addItem("Ponto");
    ui->comboBox->addItem("X");
    ui->comboBox->addItem("Triangulo");
    ui->comboBox->addItem("Retangulo");
    ui->comboBox->addItem("Linha");

    // Preenche as imagens uma cor de fundo
      QColor corDeFundo(255,255,200);
      ImgX.fill(corDeFundo);
      ImgO.fill(corDeFundo);

      // Desenha as imagens do X e do O
      QPen pen;
      QPainter painter;

      // X vermelho
        pen.setWidth(5);
        pen.setColor(Qt::black);
        painter.begin(&ImgX);
        painter.setPen(pen);
        painter.drawLine(180,180, 29,29);
        painter.drawLine(180,29, 29,180);
        painter.end();

        // O preto
        pen.setWidth(5);
        pen.setColor(Qt::black);
        painter.begin(&ImgO);
        painter.setPen(pen);
        painter.drawEllipse(QPoint(110,95), 90, 90);
        painter.end();


}



fig::~fig()
{
    delete ui;
}

void fig::exibirFig()
{
    QString arg1 = ui->comboBox->currentText();

        if(arg1=="Ponto"){
            ui->img->setPixmap(ImgO);
        }
        else if(arg1=="X"){
            ui->img->setPixmap(ImgX);
        }
        else if(arg1=="Triangulo"){

        }
        else if(arg1=="Retangulo"){

        }
        else if(arg1=="Linha"){

        }
        else{

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


