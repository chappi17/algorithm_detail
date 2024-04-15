#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n = 10;
	int a[10][10];
	int x[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > 4)
			{
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[j][n - 1 - i] = a[i][j];
		}
	}



	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				cout << x[i][j] << " ";
			}
			else
			{
				cout << setw(4) << x[i][j];

			}
		}
		cout << "\n";
	}
	cout << "\n";


	float b = 3.141592;
	std::cout << fixed<<setprecision(2) << b<<endl;
}