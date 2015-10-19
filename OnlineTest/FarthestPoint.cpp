#include <iostream>
#include <vector>
using namespace std;

double GetDistSquare(double x1, double y1, double x2, double y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void GetFarthestPoint(double centerX, double centerY, double radius)
{
	double radius2 = radius * radius;
	double shortLength = radius * 1.414 / 2;
	vector<int> intX;
	vector<int> intY;
	int intXtemp, intYtemp;
	double FarthestLength = 0;
	//上区域边界
	double upBottom = centerY + shortLength;
	double upTop = centerY + radius;
	double upLeft = centerX - shortLength;
	double upRight = centerX + shortLength;
	for (int x = int(upLeft ); x <= int(upRight + 1); ++x)
	{
		for (int y = int(upBottom ); y <= int(upTop + 1); ++y)
		{
			double distSquare = GetDistSquare(x, y, centerX, centerY);
			if( distSquare <= radius2 )
			{
				if (distSquare > FarthestLength)
				{
					FarthestLength = distSquare;
					intX.clear();
					intY.clear();
					intX.push_back(x);
					intY.push_back(y);
				}
				else if (distSquare == FarthestLength)
				{
					intX.push_back(x);
					intY.push_back(y);
				}
			}
		}
	}
	//下区域边界
	double downBottom = centerY - radius;
	double downTop = centerY - shortLength;
	double downLeft = centerX - shortLength;
	double downRight = centerX + shortLength;
	for (int x = int(downLeft ); x <= int(downRight + 1); ++x)
	{
		for (int y = int(downBottom ); y <= int(downTop + 1); ++y)
		{
			double distSquare = GetDistSquare(x, y, centerX, centerY);
			if( distSquare <= radius2 )
			{
				if (distSquare > FarthestLength)
				{
					FarthestLength = distSquare;
					intX.clear();
					intY.clear();
					intX.push_back(x);
					intY.push_back(y);
				}
				else if (distSquare == FarthestLength)
				{
					intX.push_back(x);
					intY.push_back(y);
				}
			}
		}
	}
	//左区域边界
	double leftBottom = centerY - shortLength;
	double leftTop = centerY + shortLength;
	double leftLeft = centerX - radius;
	double leftRight = centerX - shortLength;
	for (int x = int(leftLeft ); x <= int(leftRight + 1); ++x)
	{
		for (int y = int(leftBottom ); y <= int(leftTop + 1); ++y)
		{
			double distSquare = GetDistSquare(x, y, centerX, centerY);
			if( distSquare <= radius2 )
			{
				if (distSquare > FarthestLength)
				{
					FarthestLength = distSquare;
					intX.clear();
					intY.clear();
					intX.push_back(x);
					intY.push_back(y);
				}
				else if (distSquare == FarthestLength)
				{
					intX.push_back(x);
					intY.push_back(y);
				}
			}
		}
	}

	//右区域边界
	double rightBottom = centerY - shortLength;
	double rightTop = centerY + shortLength;
	double rightLeft = centerX + shortLength;
	double rightRight = centerX + radius;
	for (int x = int(rightLeft ); x <= int(rightRight + 1); ++x)
	{
		for (int y = int(rightBottom ); y <= int(rightTop + 1); ++y)
		{
			double distSquare = GetDistSquare(x, y, centerX, centerY);
			if( distSquare <= radius2 )
			{
				if (distSquare > FarthestLength)
				{
					FarthestLength = distSquare;
					intX.clear();
					intY.clear();
					intX.push_back(x);
					intY.push_back(y);
				}
				else if (distSquare == FarthestLength)
				{
					intX.push_back(x);
					intY.push_back(y);
				}
			}
		}
	}

	int maxX = -400000;
	int maxY = -400000;
	for (int i = 0; i < intX.size(); ++i)
	{
		if (intX[i] > maxX)
		{
			maxX = intX[i];
		}
	}
	for (int i = 0; i < intX.size(); ++i)
	{
		if (intX[i] == maxX && intY[i] > maxY)
		{
			maxY = intY[i];
		}
	}

	cout << maxX << " " << maxY << endl;
	return ;
}

int main()
{
	double centerX, centerY, radius;
	cin >> centerX >> centerY >> radius;
	GetFarthestPoint(centerX, centerY, radius);

	return 0;
}
