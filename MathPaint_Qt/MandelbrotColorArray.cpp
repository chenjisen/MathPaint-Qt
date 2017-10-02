#include "stdafx.h"

// ����д
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



	//ͨ��ѭ����ʼ�ж�����Ƶ�
	for (int py = 0; py < WHeight; ++py) {
		for (int px = 0; px < WWidth; ++px) {

			//�жϵ��Ƿ����ڼ���

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
/// �õ���ɫ
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


// Ŀǰ���㷨�ƺ������⣬��Ϊ�Ŵ��Ժ���ɫ��仯
/// <summary>
/// ʹ����״ͼ��
/// �õ�0~1֮�������ɵ�����
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
/// ʹ����״ͼ�����������
/// �õ�0~1֮�������ɵ�����
/// </summary>
double MandelbrotColorArray::NormalizeIterations(int iterations, double DoubleIterations)
{

	double value1 = NormalizedArray[iterations - 1];
	double value2 = NormalizedArray[iterations];
	// iteration % 1 = iter - (int)iter = fractional part of iteration.
	double value = value1 + (value2 - value1) * (DoubleIterations - (int)DoubleIterations);
	//��hueȡֵ��Χ�任��0~1
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