#include <iostream>

#include <QtWidgets/QApplication>
#include <GUI/Include/ApPanels.h>
#include <GUI/Include/JtanPanels.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ApPanels w;
	w.show();

	JtanPanels w2;
	w2.show();

	return a.exec();
}