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
	/// ���캯��
	/// </summary>
public:
	MandelbrotImage(double xmin, double xmax, double ymin, double ymax)
		:xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax)
	{
		//�õ���������
		ColorArray = new MandelbrotColorArray(xmin, xmax, ymin, ymax, WWidth, WHeight);//������������

		//�õ�ͼ��
		img = DrawImage();
	}

	
protected:

	/// <summary>
	/// ����ͼ��
	/// </summary>
	QImage* DrawImage();
};

