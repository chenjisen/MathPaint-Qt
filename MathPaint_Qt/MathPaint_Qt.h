#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MathPaint_Qt.h"

#include "MandelbrotImage.h"
#include <QString>

#define toStr QString::number

class MathPaint_Qt : public QMainWindow
{
	Q_OBJECT

public:
	MathPaint_Qt(QWidget *parent = Q_NULLPTR);

private:
	Ui::MathPaint_QtClass ui;


public:

	/// <summary>
	/// 窗口大小：644*644（1：1）
	/// </summary>
	static const int WWidth = 644, WHeight = 644;  //之前的窗口大小：1120*630
private:
	double xmin = -2.1, xmax = 0.7, ymin = -1.4, ymax = 1.4;
	double xcenter, ycenter;//xcenter = -0.7, ycenter = 0;
	MandelbrotImage* MImage=nullptr;

	/// <summary>
	/// 绘制函数
	/// </summary>
	void showImage()
	{
		static QPixmap pixmap;
		pixmap = QPixmap::fromImage(*(MImage->img));

		//在图片上绘制坐标
		DrawCoordinates(&pixmap);

		//绘制图形
		ui.imageBox->setPixmap(pixmap);

	}


	void GetNewImage()
	{
		ui.lineEditXMin->setText(toStr(xmin));
		ui.lineEditXMax->setText(toStr(xmax));
		ui.lineEditYMin->setText(toStr(ymin));
		ui.lineEditYMax->setText(toStr(ymax));
	//	Cursor = Cursors.WaitCursor;//改变光标形状

		if (MImage != nullptr) 
			delete MImage;
		MImage = new MandelbrotImage(xmin, xmax, ymin, ymax);
	//	Cursor = Cursors.Default;
	}



	/// <summary>
	/// 绘制坐标
	/// </summary>
	void DrawCoordinates(QPixmap* pixmap)
	{
		QPainter painter(pixmap);


		// 设置字体
		QFont drawFont;
		drawFont.setFamily("Arial");
		drawFont.setPointSize(12);
		painter.setFont(drawFont);

		// 设置画笔颜色
		painter.setPen(QColor("blue"));

		// 绘制文本
		double x, y;
		QString str;
		double xmin = MImage->xmin, xmax = MImage->xmax;
		double ymin = MImage->ymin, ymax = MImage->ymax;
		double dx = (xmax - xmin) / WWidth;
		double dy = (ymax - ymin) / WHeight;



		for (int px = 0; px <= WWidth; px += 100) {
			x = xmin + dx * px;
			str =toStr(x,'f',3);
			painter.drawText(px,15, str);
		}

		for (int py = 0; py <= WHeight; py += 100) {
			y = ymin + dy * py;
			str = toStr(y, 'f', 3);
			painter.drawText(0, py+15,str);
		}

	}

	void showEvent(QShowEvent *e)
	{
		GetNewImage();
		showImage();

		//	//button2.Focus();
	}



	//显示鼠标位置	
protected:
		void mouseMoveEvent(QMouseEvent* e)

	{
		QPoint point = e->pos();
		point.ry() -= ui.mainToolBar->height();//修正

		static const QRect rect = ui.imageBox->frameGeometry();
		if (rect.contains(point)) {	//鼠标在图像内
			int x = point.x() - rect.x();	//相对位置
			int y = point.y() - rect.y();

			double deltax = xmax - xmin;
			double deltay = ymax - ymin;
			xcenter = xmin + x / (double)WWidth * deltax;
			ycenter = ymin + y / (double)WHeight * deltay;

			ui.lineEditXCursor->setText(toStr(xcenter));//xcenter
			ui.lineEditYCursor->setText(toStr(ycenter));//ycenter
		}

	}
	//点击任意位置放大
	 void mousePressEvent(QMouseEvent* e)
	{
		 QPoint point = e->pos();
		 point.ry() -= ui.mainToolBar->height();//修正
		 static const QRect rect = ui.imageBox->frameGeometry();
		 if (rect.contains(point)) {

			 double deltax = xmax - xmin;
			 double deltay = ymax - ymin;
			 xmin = xcenter - deltax / 4;
			 xmax = xcenter + deltax / 4;
			 ymin = ycenter - deltay / 4;
			 ymax = ycenter + deltay / 4;
			 GetNewImage();
			 showImage();
		 }
	}

	private slots:

	//显示图形
	void showClicked()
	{
		//此时x,y的最值与TextBox有关
		xmin = ui.lineEditXMin->text().toDouble();
		xmax = ui.lineEditXMax->text().toDouble();
		ymin = ui.lineEditYMin->text().toDouble();
		ymax = ui.lineEditYMax->text().toDouble();

		//调整xm, ym至相应比例
		//选出合适的点列
		double dx = (xmax - xmin) / WWidth;
		double dy = (ymax - ymin) / WHeight;
		if (dx < dy) {
			dx = dy;
			double dxm = (WWidth * dx - (xmax - xmin)) / 2;
			xmin -= dxm;
			xmax += dxm;
		} else {
			dy = dx;
			double dym = (WHeight * dy - (ymax - ymin)) / 2;
			ymin -= dym;
			ymax += dym;
		}
		GetNewImage();
		showImage();
	}




	//private void buttonBack_Click(object sender, EventArgs e)
	//{

	//}

};
	//private void buttonPMUDLR_Click(object sender, EventArgs e)
	//{

	////放大
	//	double deltax = xmax - xmin;
	//	double deltay = ymax - ymin;
	//	xmin += deltax / 4;
	//	xmax -= deltax / 4;
	//	ymin += deltay / 4;
	//	ymax -= deltay / 4;

	////缩小
	//	double deltax = xmax - xmin;
	//	double deltay = ymax - ymin;
	//	xmin -= deltax / 2;
	//	xmax += deltax / 2;
	//	ymin -= deltay / 2;
	//	ymax += deltay / 2;


		////左
		
		//	double deltax = xmax - xmin;
	//	xmin -= deltax / 4;
	//	xmax -= deltax / 4;

	////上
	//	double deltay = ymax - ymin;
	//	ymin -= deltay / 4;
	//	ymax -= deltay / 4;


	////右
	//	double deltax = xmax - xmin;
	//	xmin += deltax / 4;
	//	xmax += deltax / 4;



	////下
	//	double deltay = ymax - ymin;
	//	ymin += deltay / 4;
	//	ymax += deltay / 4;


	//	GetNewImage();
	//	pictureBox1.Refresh();


	//}