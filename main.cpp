#include "simulation.h"
#include <QTextCodec> // подключение класса кодека текста
#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    Simulation w;
    w.show();

    return a.exec();
}
