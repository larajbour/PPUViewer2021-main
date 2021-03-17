//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.02.2021
//


#include "RenderWidget.h"
#include <QPainter>

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
{
  // to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const
{
  return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

 //    painter.setRenderHint(QPainter::Antialiasing, false);
  QColor color(0, 0, 0);
  painter.setPen(color);

  painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
  
  /*for (int x = 100; x < 300; ++x)
  {
    painter.drawPoint(x, x);
  }*/

  myDrawLine(10, 345, 150, 200);
  DC_PolarCoordinates(60, 400, 50);
  arc(50, 250, 40, 120, 60);

  myDrawLine(100, 250,250 , 50);
  myDrawLine(100, 270, 550, 150);
  arc(330,270,180,360, 80);
  myDrawLine(407, 250, 550, 150);
  DC_PolarCoordinates(330, 240, 15);
  arc(320, 130, 0, 130, 60);
  arc(342, 140, 0, 70, 60);

}


void RenderWidget::myDrawLine(float x0, float y0, float x1, float y1)
{
    QPainter painter(this);

    //    painter.setRenderHint(QPainter::Antialiasing, false);
    QColor color(255, 0, 0);
    painter.setPen(color);

    //drawLine using the Bresenham’s algorithm.
    float dx = x1 - x0;
    float dy = y1 - y0;
    float D = 2 * dx - 2 * dy;
    painter.drawPoint(x0, y0);
    float y = y0;
    float p = 2 * dy - dx;
    for (int x = x0 + 1; x <= x1; ++x) {
        if (p < 0) {
            painter.drawPoint(x, y);
            p = p + 2 * dy;
        }
        else
        {
            y = y + 1;
            painter.drawPoint(x, y);
            p = p + 2 * dy - 2 * dx;
        }
    }


}

void RenderWidget::DC_PolarCoordinates(float xc, float yc, float r) {
    QPainter painter(this);

    //    painter.setRenderHint(QPainter::Antialiasing, false);
    QColor color(255, 0, 0);
    painter.setPen(color);

    float theta = 0;
     float theta0 = 1 / r;
    while (theta < 360)
    {
        float x = xc + r * cos(theta);
        float y = yc + r * sin(theta);
        painter.drawPoint(round(x), round(y));
        theta = theta + theta0;
    }
}

void RenderWidget::arc(float xc, float yc , float d1 , float d2 , float r ){
    
    QPainter painter(this);

    //    painter.setRenderHint(QPainter::Antialiasing, false);
    QColor color(0, 0, 0);
    painter.setPen(color);
    double pi = 3.14159265359;
    float t1 = d1 * (pi / 180);
    float t2 = d2 * (pi / 180);
    float theta = t1;
    float theta0 = 1 / r;
    while (theta < t2)
    {
        float x = xc + r * cos(theta);
        float y = yc + r * sin(theta);
        painter.drawPoint(round(x), round(y));
        theta = theta + theta0;
    }
    

}



