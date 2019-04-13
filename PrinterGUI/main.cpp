#include "widget.h"
#include <QApplication>
#include <QThread>
#include "xaxisr.h"
#include "xaxisl.h"
#include "yaxisr.h"
#include "yaxisl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle("fusion");
    Widget w;
    w.show();

    return a.exec();
}
