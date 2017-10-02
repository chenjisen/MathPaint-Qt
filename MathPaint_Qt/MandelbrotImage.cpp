#include "stdafx.h"
#include "MandelbrotImage.h"
#include "MathPaint_Qt.h"

int MandelbrotImage::WWidth = MathPaint_Qt::WWidth;
int MandelbrotImage::WHeight = MathPaint_Qt::WHeight;

MandelbrotImage::MandelbrotImage()
{
}


MandelbrotImage::~MandelbrotImage()
{
	if (img!=nullptr)
		delete img;
	if (ColorArray != nullptr)
		delete ColorArray;
}

QImage* MandelbrotImage::DrawImage()
{

	QImage* img = new QImage(WWidth, WHeight, QImage::Format::Format_RGB32);

	QColor PixelColor;

	for (int py = 0; py < WHeight; ++py) {
		for (int px = 0; px < WWidth; ++px) {

			//得到颜色
			//PixelColor = IterationsToColor(iterations[px, py], DoubleIterations[px, py],
			// NormalizedArray, px, py);
			PixelColor = ColorArray->at(px, py);
			//绘制点
			img->setPixelColor(px, py, PixelColor);
		}
	}

	return img;
}