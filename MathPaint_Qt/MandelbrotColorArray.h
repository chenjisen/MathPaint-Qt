#pragma once

#include <QColor>
#include <vector>
#include <complex>

using std::complex;
using std::vector;

class MandelbrotColorArray
{


private:

	/// <summary>
	/// ���ѭ������
	/// </summary>
	static const int MaxIterations = 1000;

	/// <summary>
	/// ���ĸ�����ģ
	/// </summary>
	static const int EscapeRadius = 256;  //2^8
	static const int EscapeRadius2 = EscapeRadius*EscapeRadius;

	/// <summary>
	/// �����ڴ�ֵʱȡ����ɫ
	/// </summary>
	static const int BGIterations = 11;

private:

	// z�����Ĵ���
	vector<vector<int>> iterationsArray;

	vector<vector<double>> DoubleIterationsArray;

	double NormalizedArray[MaxIterations];// = { 0.0 };//��ʼֵΪ0

	//��ɫ����
	const QColor BGColor=QColor("orange");
	const QColor CoreColor=QColor("black");

	int WWidth, WHeight;


	void GetNormalizedArray(double NormalizedArray[], int histogram[]);

	double NormalizeIterations(int iterations, double DoubleIterations);



public:
	MandelbrotColorArray(double xmin, double xmax, double ymin, double ymax, int WWidth, int WHeight);
	~MandelbrotColorArray() {}


	QColor at(int px, int py);

};


