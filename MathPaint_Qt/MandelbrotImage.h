#pragma once

class MandelbrotImage
{
public:
	MandelbrotImage();
	~MandelbrotImage();


public:
	QImage* img=nullptr;
public:
	double xmin, xmax, ymin, ymax;


protected:
	static int WWidth, WHeight;
private:
	MandelbrotColorArray* ColorArray=nullptr;

	/// <summary>
	/// 构造函数
	/// </summary>
public:
	MandelbrotImage(double xmin, double xmax, double ymin, double ymax)
		:xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax)
	{
		//得到迭代次数
		ColorArray = new MandelbrotColorArray(xmin, xmax, ymin, ymax, WWidth, WHeight);//迭代次数数组

		//得到图像
		img = DrawImage();
	}

	
protected:

	/// <summary>
	/// 绘制图形
	/// </summary>
	QImage* DrawImage();
};

