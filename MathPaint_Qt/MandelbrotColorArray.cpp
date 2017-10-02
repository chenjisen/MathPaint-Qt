#include "stdafx.h"

// 待重写
MandelbrotColorArray::MandelbrotColorArray(double xmin, double xmax, double ymin, double ymax,
	int WWidth, int WHeight)
{
	this->WWidth = WWidth;
	this->WHeight = WHeight;
	iterationsArray = vector<vector<int>>(WWidth, vector<int>(WHeight, 0));
	DoubleIterationsArray = vector<vector<double>>(WWidth, vector<double>(WHeight, 0));
	for (auto& d : NormalizedArray) d = 0;


	int histogram[MaxIterations + 1] = { 0 };

	double dx = (xmax - xmin) / WWidth;
	double dy = (ymax - ymin) / WHeight;

	double creal, cimag, zreal, zimag, zrealtemp;

	double nu;



	//通过循环开始判断与绘制点
	for (int py = 0; py < WHeight; ++py) {
		for (int px = 0; px < WWidth; ++px) {

			//判断点是否属于集合

			creal = xmin + dx * px;
			cimag = ymin + dy * py; //x=xmin+dx*px, y=ymin+dy*py
			zreal = zimag = 0.0;

			while (zreal*zreal + zimag*zimag < EscapeRadius2 && iterationsArray[px][py] < MaxIterations) {

				zrealtemp = zreal * zreal - zimag * zimag + creal;
				zimag = 2 * zimag * zreal + cimag;	//z = z * z + c;
				zreal = zrealtemp;
				++iterationsArray[px][py];
			}

			DoubleIterationsArray[px][py] = iterationsArray[px][py];

			++histogram[iterationsArray[px][py]];
			if (iterationsArray[px][py] < MaxIterations && iterationsArray[px][py] > BGIterations) {

				// potential function
				nu = log(log(zreal*zreal + zimag*zimag) / 2 / log(2)) / log(2);
				DoubleIterationsArray[px][py] += 3 - nu;

				//++histogram[iterations[px][py]];
			}

		}
	}

	GetNormalizedArray(NormalizedArray, histogram);

}

/// <summary>
/// 得到颜色
/// </summary>
QColor MandelbrotColorArray::at(int px, int py)
{
	int iterations = iterationsArray[px][py];

	if (iterations >= MaxIterations)
		return CoreColor;
	else if (iterations <= BGIterations)
		return BGColor;     //return HueToColor(WxWyToBGHue(px, py));
	else {
		double DoubleIterations = DoubleIterationsArray[px][py];
		return Palette::HueToCyclicColor(NormalizeIterations(iterations, DoubleIterations));
	}

}


// 目前的算法似乎有问题，因为放大以后颜色会变化
/// <summary>
/// 使用柱状图法
/// 得到0~1之间的数组成的数组
///// </summary>
void  MandelbrotColorArray::GetNormalizedArray(double NormalizedArray[], int histogram[])
{
	double total = 0;
	for (int i = BGIterations; i < MaxIterations; ++i)
		total += histogram[i];


	for (int i = BGIterations; i < MaxIterations; ++i) {
		NormalizedArray[i] = NormalizedArray[i - 1] + histogram[i] / total;
	}

}


/// <summary>
/// 使用柱状图法和线性拟合
/// 得到0~1之间的数组成的数组
/// </summary>
double MandelbrotColorArray::NormalizeIterations(int iterations, double DoubleIterations)
{

	double value1 = NormalizedArray[iterations - 1];
	double value2 = NormalizedArray[iterations];
	// iteration % 1 = iter - (int)iter = fractional part of iteration.
	double value = value1 + (value2 - value1) * (DoubleIterations - (int)DoubleIterations);
	//将hue取值范围变换成0~1
	double valueMin = NormalizedArray[BGIterations];
	double valueMax = NormalizedArray[MaxIterations - 1];

	value = (value - valueMin) / (valueMax - valueMin);

	return value;
}

/*double BGPixelNormalization(int px, int py)
{
double z = px + py;
int max = WWidth + WHeight;
int min = 0;
double maxHue = 0.5;//0.2
double minHue = 0;//0.05

if (z > max) return maxHue;
if (z < min) return minHue;
return minHue + ((z - min) / (max - min)) * (maxHue - minHue);
}*/