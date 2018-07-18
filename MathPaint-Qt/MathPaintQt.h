#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MathPaintQt.h"

class MathPaintQt : public QMainWindow
{
	Q_OBJECT

public:
	MathPaintQt(QWidget *parent = Q_NULLPTR);

private:
	Ui::MathPaintQtClass ui;
};
