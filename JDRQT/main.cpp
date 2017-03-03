#include "widget.h"
#include "displaycharactersheet.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    displayCharacterSheet d;
    d.show();
    Widget w;
    w.show();

    return a.exec();
}
