#ifndef PAINTHELPER_H
#define PAINTHELPER_H
#include "QWidget"
#include "QPainter"
class PaintHelper : public QWidget
{
    Q_OBJECT
private:
    QPixmap *buffer;

public:
    explicit PaintHelper(QWidget *parent = 0) : QWidget(parent)
    {
        buffer=new QPixmap(350,250);// this is the fixe width of this widget so
        buffer->fill(Qt::cyan);
    }

signals:
public slots:
    void drawCircle(int cx, int cy, int r){


        QPainter painter(buffer);
        painter.setBrush(QBrush(QColor(0,0,255)));

        // A part of mid-point algorithm to draw 1/8 pacrt of circle
        int x1=0,y1=r;
        int p=1-r;
        for(int i=0;y1>=x1;i++){
            painter.drawPoint(x1+cx,y1+cy);
            x1++;
            if(p>0){
                p+=3+x1;
            }
            else{
                y1--;
                p+=2*x1-2*y1;
                p++;
            }
        }
        this->repaint();
    }



    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.drawPixmap(0,0,*buffer);
    }
};

#endif // PAINTHELPER_H
