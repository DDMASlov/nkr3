#include "class.hpp"
int main()
{
	if (autotest() == 0)
	{
		int* ch1;
		int* ch2;
		size_t n1, n2;
		srand(time(NULL));
		n1 = 1 + (rand() % 100);
		n2 = 1 + (rand() % 100);
		ch1 = new int[n1];
		ch2 = new int[n2];
		for (size_t i = 0; i < n1; i++)
		{
			if (i == 0)
			{
				ch1[i] = (pow(-1, rand() % 2)) * (1 + (rand() % 9));
			}
			else
			{
				ch1[i] = 1 + (rand() % 9);
			}
		}
		for (size_t i = 0; i < n2; i++)
		{
			if (i == 0)
			{
				ch2[i] = (pow(-1, rand() % 2)) * (1 + (rand() % 9));
			}
			else
			{
				ch2[i] = 1 + (rand() % 9);
			}
		}
		CHislo a(ch1, n1), b(ch2, n2);
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		CHislo sum;
		sum = a + b;
		CHislo razn;
		razn = a - b;
		cout << "a+b = " << sum << endl;
		cout << "a - b = " << razn << endl;
		delete[] ch1;
		delete[] ch2;
		return 0;
	}
	else
	{
		return 1;
	}
}