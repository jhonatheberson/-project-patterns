#ifndef FIG_H
#define FIG_H

#include <QMainWindow>
#include "ajuda.h"
#include <QMainWindow>
#include <QPixmap>
#include <QLabel>


namespace Ui {
class fig;
}

class fig : public QMainWindow
{
    Q_OBJECT

public:
    explicit fig(QWidget *parent = nullptr);
    ~fig();

private slots:
    void on_Desenhar_clicked();

    void on_actionSair_triggered();

    void on_actionAjuda_triggered();

    void exibirFig();

private:
    Ui::fig *ui;
    QPixmap Img;
    QPixmap ImgX;
    QPixmap ImgO;
    QLabel NumX;
    QLabel NumO;
    ajuda help;
};

#endif // FIG_H
