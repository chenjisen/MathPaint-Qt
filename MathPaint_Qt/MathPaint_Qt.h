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
	/// ���ڴ�С��644*644��1��1��
	/// </summary>
	static const int WWidth = 644, WHeight = 644;  //֮ǰ�Ĵ��ڴ�С��1120*630
private:
	double xmin = -2.1, xmax = 0.7, ymin = -1.4, ymax = 1.4;
	double xcenter, ycenter;//xcenter = -0.7, ycenter = 0;
	MandelbrotImage* MImage=nullptr;

	/// <summary>
	/// ���ƺ���
	/// </summary>
	void showImage()
	{
		static QPixmap pixmap;
		pixmap = QPixmap::fromImage(*(MImage->img));

		//��ͼƬ�ϻ�������
		DrawCoordinates(&pixmap);

		//����ͼ��
		ui.imageBox->setPixmap(pixmap);

	}


	void GetNewImage()
	{
		ui.lineEditXMin->setText(toStr(xmin));
		ui.lineEditXMax->setText(toStr(xmax));
		ui.lineEditYMin->setText(toStr(ymin));
		ui.lineEditYMax->setText(toStr(ymax));
	//	Cursor = Cursors.WaitCursor;//�ı�����״

		if (MImage != nullptr) 
			delete MImage;
		MImage = new MandelbrotImage(xmin, xmax, ymin, ymax);
	//	Cursor = Cursors.Default;
	}



	/// <summary>
	/// ��������
	/// </summary>
	void DrawCoordinates(QPixmap* pixmap)
	{
		QPainter painter(pixmap);


		// ��������
		QFont drawFont;
		drawFont.setFamily("Arial");
		drawFont.setPointSize(12);
		painter.setFont(drawFont);

		// ���û�����ɫ
		painter.setPen(QColor("blue"));

		// �����ı�
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



	//��ʾ���λ��	
protected:
		void mouseMoveEvent(QMouseEvent* e)

	{
		QPoint point = e->pos();
		point.ry() -= ui.mainToolBar->height();//����

		static const QRect rect = ui.imageBox->frameGeometry();
		if (rect.contains(point)) {	//�����ͼ����
			int x = point.x() - rect.x();	//���λ��
			int y = point.y() - rect.y();

			double deltax = xmax - xmin;
			double deltay = ymax - ymin;
			xcenter = xmin + x / (double)WWidth * deltax;
			ycenter = ymin + y / (double)WHeight * deltay;

			ui.lineEditXCursor->setText(toStr(xcenter));//xcenter
			ui.lineEditYCursor->setText(toStr(ycenter));//ycenter
		}

	}
	//�������λ�÷Ŵ�
	 void mousePressEvent(QMouseEvent* e)
	{
		 QPoint point = e->pos();
		 point.ry() -= ui.mainToolBar->height();//����
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

	//��ʾͼ��
	void showClicked()
	{
		//��ʱx,y����ֵ��TextBox�й�
		xmin = ui.lineEditXMin->text().toDouble();
		xmax = ui.lineEditXMax->text().toDouble();
		ymin = ui.lineEditYMin->text().toDouble();
		ymax = ui.lineEditYMax->text().toDouble();

		//����xm, ym����Ӧ����
		//ѡ�����ʵĵ���
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

	////�Ŵ�
	//	double deltax = xmax - xmin;
	//	double deltay = ymax - ymin;
	//	xmin += deltax / 4;
	//	xmax -= deltax / 4;
	//	ymin += deltay / 4;
	//	ymax -= deltay / 4;

	////��С
	//	double deltax = xmax - xmin;
	//	double deltay = ymax - ymin;
	//	xmin -= deltax / 2;
	//	xmax += deltax / 2;
	//	ymin -= deltay / 2;
	//	ymax += deltay / 2;


		////��
		
		//	double deltax = xmax - xmin;
	//	xmin -= deltax / 4;
	//	xmax -= deltax / 4;

	////��
	//	double deltay = ymax - ymin;
	//	ymin -= deltay / 4;
	//	ymax -= deltay / 4;


	////��
	//	double deltax = xmax - xmin;
	//	xmin += deltax / 4;
	//	xmax += deltax / 4;



	////��
	//	double deltay = ymax - ymin;
	//	ymin += deltay / 4;
	//	ymax += deltay / 4;


	//	GetNewImage();
	//	pictureBox1.Refresh();


	//}