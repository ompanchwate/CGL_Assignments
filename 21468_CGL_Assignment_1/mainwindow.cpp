#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    float x=ui->textEdit->toPlainText().toFloat();
    float y=ui->textEdit_2->toPlainText().toFloat();
    float l=ui->textEdit_3->toPlainText().toFloat();
    float b=ui->textEdit_4->toPlainText().toFloat();
    rectangle(x,y,l,b);
}

void MainWindow::on_pushButton_2_clicked()
{
    float x=ui->textEdit->toPlainText().toFloat();
    float y=ui->textEdit_2->toPlainText().toFloat();
    float l=ui->textEdit_3->toPlainText().toFloat();
    float b=ui->textEdit_4->toPlainText().toFloat();
    rhombus(x,y,l,b);
}

void MainWindow::on_pushButton_3_clicked()
{
    float x=ui->textEdit->toPlainText().toFloat();
    float y=ui->textEdit_2->toPlainText().toFloat();
    float l=ui->textEdit_3->toPlainText().toFloat();
    float b=ui->textEdit_4->toPlainText().toFloat();

    float xmid = (x+(x+l))/2;
    float ymid = (y +(y+b))/2;
    float r = ((l*b)/(2*sqrt((l*l)+(b*b))));

    Circle(xmid,ymid,r);
}

void MainWindow::rectangle(float x, float y, float l, float b)
{
    dda_line(x,y,x+l,y);
    dda_line(x,y,x,y+b);
    dda_line(x+l,y,x+l,y+b);
    dda_line(x,y+b,x+l,y+b);
}


void MainWindow::rhombus(float x, float y, float l, float b)
{
    float xmid = (x+(x+l))/2;
    float ymid = (y +(y+b))/2;
    dda_line(xmid, y, x, ymid);
    dda_line(xmid, y, x+l, ymid);
    dda_line(x+l,ymid,xmid,y+b);
    dda_line(x,ymid,xmid,y+b);
}

void MainWindow::Circle(float p, float q, float r){
    float d,x,y;

    d = 3-2*r;

    x = 0;
    y = r;

    while(x<y){
         img.setPixel(x+p, y+q,qRgb(255,0,0));
         img.setPixel(y+p, x+q,qRgb(0,255,0));
         img.setPixel(-y+p, x+q,qRgb(0,0,255));
         img.setPixel(-x+p, y+q,qRgb(0,255,0));
         img.setPixel(-x+p, -y+q,qRgb(255,0,0));
         img.setPixel(-y+p, -x+q,qRgb(0,255,0));
         img.setPixel(y+p, -x+q,qRgb(0,0,255));
         img.setPixel(x+p, q-y,qRgb(0,255,0));

         if(d<0){
             d = d+4*x+6;
             x = x+1;

         }else{
             d = d+4*(x-y)+10;
             x = x+1;
             y = y-1;
         }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::dda_line(float x1,float y1, float x2, float y2){

    float x,y;
    float dx,dy;
    float steps;
    float xinc, yinc;


    dx = x2-x1;

    dy = y2-y1;


    if(abs(dx)>abs(dy)){
        steps = abs(dx);
    }else{
        steps = abs(dy);
    }

    xinc = dx/steps;
    yinc = dy/steps;

    x = x1;
    y = y1;
    int i = 0;
    while(i<steps){
        x = x + xinc;
        y = y + yinc;

        img.setPixel(x,y,qRgb(0,255,0));
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));



}

