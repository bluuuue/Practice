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
		cout << "S(m):" << endl;
		cin >> S;
		cout << "L(m):" << endl;
		cin >> L;
		cout << "Q(m3/d):" << endl;
		cin >> Q;
		cout << "M(m):" << endl;
		cin >> M;
		cout << "r(m):" << endl;
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
		
		cout << endl << "Result: " << endl;
		cout << "  K(m/d): " << K << endl;
		cout << "  R(m):   " << R << endl << endl;

		cout << "Enter 'c' to continue, or anyelse char to end: " << endl;
		cin >> flag;
		//flag = getchar();
		cout << endl;
	}

	return 0;
}
