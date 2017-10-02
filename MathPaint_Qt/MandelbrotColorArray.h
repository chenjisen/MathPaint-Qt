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
	/// 最大循环次数
	/// </summary>
	static const int MaxIterations = 1000;

	/// <summary>
	/// 最大的复数的模
	/// </summary>
	static const int EscapeRadius = 256;  //2^8
	static const int EscapeRadius2 = EscapeRadius*EscapeRadius;

	/// <summary>
	/// 不大于此值时取背景色
	/// </summary>
	static const int BGIterations = 11;

private:

	// z迭代的次数
	vector<vector<int>> iterationsArray;

	vector<vector<double>> DoubleIterationsArray;

	double NormalizedArray[MaxIterations];// = { 0.0 };//初始值为0

	//颜色变量
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


