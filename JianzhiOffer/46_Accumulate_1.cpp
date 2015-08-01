#include <iostream>
using namespace std;

class Temp
{
	public:
	Temp()
	{
		++N;
		Sum += N;
	}

	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

	static int GetSum()
	{
		return Sum;
	}
	
private:
	static int N;
	static int Sum;
};

int Temp::N ;
int Temp::Sum ;

int main()
{
	Temp::Reset();

	Temp *a = new Temp[100];
	delete[] a;
	a = NULL;

	cout << Temp::GetSum() << endl;

	return 0;
}
