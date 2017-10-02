#include "stdafx.h"
#include "MathPaint_Qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MathPaint_Qt w;
	w.show();
	return a.exec();
}
