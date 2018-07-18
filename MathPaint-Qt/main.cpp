#include "stdafx.h"
#include "MathPaintQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MathPaintQt w;
	w.show();
	return a.exec();
}
