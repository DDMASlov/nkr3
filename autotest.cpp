#include "autotest.hpp"
int autotest()
{
	if (autotest1() && autotest2() && autotest3() == 1)
	{
		cout << "Autotest passed!" << endl;
		return 0;
	}
	else
	{
		cout << "Autotest failed!!" << endl;
		return 1;
	}
}
int autotest1()
{
	int a[3] = { 1,2,3 };
	int b[4] = { 1,2,3,4 };
	int c[4] = { 1,3,5,7 };
	int d[4] = { -1,1,1,1 };
	CHislo a1(a, 3);
	CHislo b1(b, 4);
	CHislo sum;
	sum = a1 + b1;
	CHislo razn;
	razn = a1 - b1;
	if (sum.Compare(c, 4) && razn.Compare(d, 4))
	{
		cout << "Autotest1 passed!" << endl;
		return 1;
	}
	else
	{
		cout << "Autotest1 failed!!" << endl;
		return 0;
	}
}
int autotest2()
{
	int a[3] = { 1,2,3 };
	int b[4] = { -1,2,3,4 };
	int c[4] = { -1,1,1,1 };
	int d[4] = { 1,3,5,7 };
	CHislo a1(a, 3);
	CHislo b1(b, 4);
	CHislo sum;
	sum = a1 + b1;
	CHislo razn;
	razn = a1 - b1;
	if (sum.Compare(c, 4) && razn.Compare(d, 4))
	{
		cout << "Autotest2 passed!" << endl;
		return 1;
	}
	else
	{
		cout << "Autotest2 failed!!" << endl;
		return 0;
	}
}
int autotest3()
{
	int a[3] = { 1,2,3 };
	int b[3] = { 1,2,3 };
	int c[3] = { 2,4,6 };
	int d[1] = { 0 };
	CHislo a1(a, 3);
	CHislo b1(b, 3);
	CHislo sum;
	sum = a1 + b1;
	CHislo razn;
	razn = a1 - b1;
	if (sum.Compare(c, 3) && razn.Compare(d, 1))
	{
		cout << "Autotest3 passed!" << endl;
		return 1;
	}
	else
	{
		cout << "Autotest3 failed!!" << endl;
		return 0;
	}
}