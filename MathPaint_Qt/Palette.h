#pragma once

#include <QColor>

class Palette
{
public:
	Palette();
	~Palette();

	/// <summary>
	/// 返回色相不同的可循环的颜色
	/// </summary>
	static QColor HueToColor(double hue)
	{
		// 0<=hue<=1

		int r = 0, g = 0, b = 0;
		double dDeltaHue = hue * 5.0;
		int iHue = (int)dDeltaHue;
		dDeltaHue -= iHue;
		switch (iHue) {
		case 0:
			r = 255;
			g = (int)(255 * dDeltaHue);
			break;
		case 1:
			g = 255;
			r = (int)(255 - dDeltaHue * 255);
			break;
		case 2:
			g = 255;
			b = (int)(dDeltaHue * 255);
			break;
		case 3:
			b = 255;
			g = (int)(255 - dDeltaHue * 255);
			break;
		case 4:
			b = 255;
			r = (int)(dDeltaHue * 255);
			break;
		case 5: //hue=1
			b = 255;
			r = 255;
			break;
		}
		return QColor(r, g, b);
	}


	/// <summary>
	/// 返回色相不同的可循环的颜色
	/// </summary>
	static QColor HueToCyclicColor(double hue)
	{
		if (hue <= 0.5)
			return HueToColor(hue * 2);
		else
			return HueToColor(2 - hue * 2);
	}

	/// <summary>
	/// 返回亮度不同的颜色
	/// </summary>
	static QColor LightnessToCyclicColor(double light)
	{
		return QColor("white");
	}

	/// <summary>
	/// 返回色相、亮度不同的可循环的颜色
	/// </summary>
	static QColor HLToCyclicColor(double value)
	{
		return QColor("white");
	}

	/// <summary>
	/// 返回不同的灰色
	/// </summary>
	static QColor LightnessToGray(double value)
	{
		int rgb = (int)(value * 255);
		return QColor(rgb, rgb, rgb);
	}
};

