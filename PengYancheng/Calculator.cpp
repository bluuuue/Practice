#include <math.h>
#include <iostream>
using namespace std;

#define PI 3.141592654
#define E 2.718282

int main()
{
	double K = -1;
	double S = -1;
	double R = -1;
	double L = -1;
	double Q = -1;
	double M = -1;
	double r = -1;

	char flag = 'c';
	while(flag == 'c')
	{
		cout << "抽水井中水位降深S(m)：" << endl;
		cin >> S;
		cout << "过滤器长度L(m)：" << endl;
		cin >> L;
		cout << "抽水井流量Q(m3/d)：" << endl;
		cin >> Q;
		cout << "承压含水层厚度M(m)：" << endl;
		cin >> M;
		cout << "抽水井半径r(m)：" << endl;
		cin >> r;

		if (M<=L)
		{
			R = 1;
			while ( fabs((R/(10*S))*(R/(10*S)) - Q * (log(R/r)/log(E)) / (2*PI*M*S)) > 0.0001 && R <= 1000)
			{
				R += 0.0001;
			}
			K = (R/(10*S))*(R/(10*S)); 
		}
		else
		{
			R = 1;
			while ( fabs((R/(10*S))*(R/(10*S)) - Q * ((log(R/r)/log(E)) + (M-L)*(log(1.12*M/(PI*r))/log(E))/L ) / (2*PI*M*S)) > 0.0001 && R <= 1000)
			{
				R += 0.0001;
			}
			K = (R/(10*S))*(R/(10*S)); 

		}
		
		cout << endl << "结果：" << endl;
		cout << "  渗透系数K(m/d)：" << K << endl;
		cout << "  影响半径R(m)：" << R << endl << endl;

		cout << "继续请输入“c”，否则输入其他字符：" << endl;
		scanf("%c",&flag);
		flag = getchar();
		cout << endl;
	}

	return 0;
}
