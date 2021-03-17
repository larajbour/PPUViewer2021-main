//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.04.2018
//


#pragma once

#include <QWidget>

class RenderWidget : public QWidget
{
    Q_OBJECT

  public:
    RenderWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

	  void myDrawLine(float x1, float y1, float x2, float y2);
      void DC_PolarCoordinates(float xc, float yc, float r);
      void arc(float xc, float yc, float x, float y, float r);
      double Convert(double degree);

  protected:
    void paintEvent(QPaintEvent *event) override;

};
