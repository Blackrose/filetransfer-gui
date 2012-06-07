#include <QtGui/QApplication>
#include <QTranslator>
#include "widget.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator trans;
	Widget w;

	trans.load("text_zh.qm");
	a.installTranslator(&trans);

    //loginDialog ld;
    //QFont font("wenquanyi",12,QFont::Bold);

    //w.setFont(font);
    w.show();

    return a.exec();
}
