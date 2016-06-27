
#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double Q,r,H,S;
	double k,R;
	char goon;
	while (1)
	{
		cout << "输入抽水井涌水量Q(m3/d)：" << endl;
		cin >> Q;
		cout << "输入含水层厚度H(m)：" << endl;
		cin >> H;
		cout << "输入抽水井水位下降值S(m)：" << endl;
		cin >> S;
		cout << "输入抽水井半径r(m)：" << endl;
		cin >> r;

		bool flag = false;

		for (R = 1; R < 1000; )
		{
			k = 0.732 * Q * (log(R/r)/log(10)) / (2*H - S) / S;

			if (abs(R - 2 * S * sqrt(H * k)) < 0.1) 
			{
				flag = true;
				break;
			}

			R += 0.001;
		}

		if (flag)
		{
			cout << endl << "结果：" << endl;
			cout << "  渗透系数k：" << k << "(m/d)" << endl;
			cout << "  影响半径R：" << R << "(m)" << endl;
		}
		else
		{
			cout << endl << "无结果" << endl;
		}
		cout << endl;

		cout << "是否进入下次运算（y/n）:" << endl;
		cin >> goon;
		if (goon == 'y' || goon == 'Y')
			continue;
		else
			break;
	}

	return 0;
}
