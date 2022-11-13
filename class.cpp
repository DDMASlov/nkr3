#include "class.hpp"
CHislo::CHislo()
{
	el = nullptr;
	size = 0;
}
CHislo::CHislo(const int* a, size_t b)
{
	size = b;
	el = shared_ptr<int[]>(new int[b]);
	for (size_t i = 0; i < b; i++)
	{
		el[i] = a[i];
	}
}
CHislo::CHislo(const CHislo& other)
{
	size = other.size;
	el = other.el;
	for (size_t i = 0; i < size; i++)
	{
		el[i] = other.el[i];
	}
}
CHislo CHislo::operator+(const CHislo& other)
{
	CHislo rez;
	int znak1 = 0, znak2 = 0;
	int ktob = 0;
	size_t sizemax = size + 1;
	int* vec;
	int* nvec;
	if (el[0] < 0)
	{
		znak1 = 1;
		el[0] = (-1) * el[0];
	}
	if (other.el[0] < 0)
	{
		znak2 = 1;
		other.el[0] = (-1) * other.el[0];
	}
	if (size > other.size)
	{
		ktob = 1;
	}
	if (other.size > size)
	{
		ktob = 2;
		sizemax = other.size + 1;
	}
	vec = new int[sizemax];
	for (size_t i = 0; i < sizemax; i++)
		vec[i] = 0;
	if (ktob == 2)
	{
		for (size_t i = 1; i < sizemax; i++)
		{
			vec[i] = other.el[i - 1];
		}
	}
	if (ktob == 1)
	{
		for (size_t i = 1; i < sizemax; i++)
		{
			vec[i] = el[i - 1];
		}
	}
	if (ktob == 0)
	{
		int ch = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (el[i] > other.el[i])
			{
				ch = 1;
				i = size;
			}
			if (el[i] < other.el[i])
			{
				ch = 2;
				i = size;
			}
		}
		if ((ch == 0) || (ch == 1))
		{
			for (size_t i = 1; i < sizemax; i++)
			{
				vec[i] = el[i - 1];
			}
			ktob = 1;
		}
		if (ch == 2)
		{
			for (size_t i = 0; i < size; i++)
			{
				vec[i + 1] = other.el[i];
			}
			ktob = 2;
		}
	}
	if (((znak1 == 1) && (znak2 == 1)) || ((znak1 == 0) && (znak2 == 0)))
	{
		if (ktob == 1)
		{
			for (size_t i = 0; i < other.size; i++)
			{
				vec[sizemax - 1 - i] = vec[sizemax - 1 - i] + other.el[other.size - 1 - i];
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
			for (size_t i = other.size; i < sizemax - 1; i++)
			{
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
		}
		if (ktob == 2)
		{
			for (size_t i = 0; i < size; i++)
			{
				vec[sizemax - 1 - i] = vec[sizemax - 1 - i] + el[size - 1 - i];
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
			for (size_t i = size; i < sizemax - 1; i++)
			{
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
		}
		if (znak1 == 1)
		{
			if (vec[0] == 0)
				vec[1] = (-1) * vec[1];
			else
				vec[0] = (-1) * vec[0];
		}
		if (vec[0] == 0)
		{
			for (size_t i = 1; i < sizemax; i++)
			{
				vec[i - 1] = vec[i];
			}
			sizemax -= 1;
		}
		nvec = new int[sizemax];
		for (size_t i = 0; i < sizemax; i++)
		{
			nvec[i] = vec[i];
		}
		delete[] vec;
	}
	else
	{
		if (ktob == 1)
		{
			for (size_t i = 0; i < other.size; i++)
			{
				vec[sizemax - 1 - i] = 10 + vec[sizemax - 1 - i] - other.el[other.size - 1 - i];
				if (vec[sizemax - 1 - i] < 10)
					vec[sizemax - i - 2] -= 1;
				else
					vec[sizemax - 1 - i] %= 10;
			}
		}
		if (ktob == 2)
		{
			for (size_t i = 0; i < size; i++)
			{
				vec[sizemax - 1 - i] = 10 + vec[sizemax - i - 1] - el[size - 1 - i];
				if (vec[sizemax - 1 - i] < 10)
					vec[sizemax - i - 2] -= 1;
				else
					vec[sizemax - i - 1] %= 10;
			}
		}
		size_t kolvo = 0;
		for (size_t i = 0; i < sizemax; i++)
		{
			if (vec[i] == 0)
				kolvo++;
			else
			{
				i = sizemax;
			}
		}
		sizemax = sizemax - kolvo;
		if (sizemax == 0)
		{
			sizemax = 1;
			kolvo = 0;
		}
		nvec = new int[sizemax];
		for (size_t i = 0; i < sizemax; i++)
		{
			nvec[i] = vec[kolvo + i];
		}
		delete[] vec;
		if (((znak1 == 1) && (ktob == 1)) || ((znak2 == 1) && (ktob == 2)))
			nvec[0] = (-1) * nvec[0];
	}
	rez.size = sizemax;
	shared_ptr<int[]> cel(new int[sizemax]);
	rez.el = cel;
	for (size_t i = 0; i < rez.size; i++)
	{
		rez.el[i] = nvec[i];
	}
	if (znak1 == 1)
		el[0] = (-1) * el[0];
	if (znak2 == 1)
		other.el[0] = (-1) * other.el[0];
	delete[] nvec;
	return rez;
}
CHislo CHislo::operator-(const CHislo& other)
{
	CHislo rez;
	int znak1 = 0, znak2 = 0;
	int ktob = 0;
	size_t sizemax = size + 1;
	int* vec;
	int* nvec;
	if (el[0] < 0)
	{
		znak1 = 1;
		el[0] = (-1) * el[0];
	}
	if (other.el[0] < 0)
	{
		znak2 = 1;
		other.el[0] = (-1) * other.el[0];
	}
	if (size > other.size)
	{
		ktob = 1;
	}
	if (other.size > size)
	{
		ktob = 2;
		sizemax = other.size + 1;
	}
	vec = new int[sizemax];
	for (size_t i = 0; i < sizemax; i++)
		vec[i] = 0;
	if (ktob == 2)
	{
		for (size_t i = 1; i < sizemax; i++)
		{
			vec[i] = other.el[i - 1];
		}
	}
	if (ktob == 1)
	{
		for (size_t i = 1; i < sizemax; i++)
		{
			vec[i] = el[i - 1];
		}
	}
	if (ktob == 0)
	{
		int ch = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (el[i] > other.el[i])
			{
				ch = 1;
				i = size;
			}
			if (el[i] < other.el[i])
			{
				ch = 2;
				i = size;
			}
		}
		if ((ch == 0) || (ch == 1))
		{
			for (size_t i = 1; i < sizemax; i++)
			{
				vec[i] = el[i - 1];
			}
			ktob = 1;
		}
		if (ch == 2)
		{
			for (size_t i = 0; i < size; i++)
			{
				vec[i + 1] = other.el[i];
			}
			ktob = 2;
		}
	}
	if (((znak1 == 0) && (znak2 == 1)) || ((znak1 == 1) && (znak2 == 0)))
	{
		int prev = 0;
		if (ktob == 1)
		{
			for (size_t i = 0; i < other.size; i++)
			{

				vec[sizemax - 1 - i] = vec[sizemax - 1 - i] + other.el[other.size - 1 - i];
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
			for (size_t i = other.size; i < sizemax - 1; i++)
			{
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
		}
		if (ktob == 2)
		{
			for (size_t i = 0; i < size; i++)
			{
				vec[sizemax - 1 - i] = vec[sizemax - 1 - i] + el[size - 1 - i];
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
			for (size_t i = size; i < sizemax - 1; i++)
			{
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
		}
		if (znak1 == 1)
		{
			if (vec[0] == 0)
				vec[1] = (-1) * vec[1];
			else
				vec[0] = (-1) * vec[0];
		}
		if (vec[0] == 0)
		{
			for (size_t i = 1; i < sizemax; i++)
			{
				vec[i - 1] = vec[i];
			}
			sizemax -= 1;
		}
		nvec = new int[sizemax];
		for (size_t i = 0; i < sizemax; i++)
		{
			nvec[i] = vec[i];
		}
		delete[] vec;
	}
	else
	{
		if (ktob == 1)
		{
			for (size_t i = 0; i < other.size; i++)
			{
				vec[sizemax - 1 - i] = 10 + vec[sizemax - 1 - i] - other.el[other.size - 1 - i];
				if (vec[sizemax - 1 - i] < 10)
					vec[sizemax - i - 2] -= 1;
				else
					vec[sizemax - 1 - i] %= 10;
			}
			for (size_t i = other.size; i < sizemax - 1; i++)
			{
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
		}
		if (ktob == 2)
		{
			for (size_t i = 0; i < size; i++)
			{
				vec[sizemax - 1 - i] = 10 + vec[sizemax - i - 1] - el[size - 1 - i];
				if (vec[sizemax - 1 - i] < 10)
					vec[sizemax - i - 2] -= 1;
				else
					vec[sizemax - i - 1] %= 10;
			}
			for (size_t i = size; i < sizemax - 1; i++)
			{
				if (vec[sizemax - 1 - i] >= 10)
				{
					vec[sizemax - 1 - i] = vec[sizemax - 1 - i] % 10;
					vec[sizemax - i - 2] += 1;
				}
			}
		}
		size_t kolvo = 0;
		for (size_t i = 0; i < sizemax; i++)
		{
			if (vec[i] == 0)
				kolvo++;
			else
			{
				i = sizemax;
			}
		}
		sizemax = sizemax - kolvo;
		if (sizemax == 0)
		{
			sizemax = 1;
			kolvo = 0;
		}
		nvec = new int[sizemax];
		for (size_t i = 0; i < sizemax; i++)
		{
			nvec[i] = vec[kolvo + i];
		}
		delete[] vec;
		if ((ktob == 2) && (znak2 == 0))
			nvec[0] = (-1) * nvec[0];
	}
	rez.size = sizemax;
	shared_ptr<int[]> cel(new int[sizemax]);
	rez.el = cel;
	for (size_t i = 0; i < rez.size; i++)
	{
		rez.el[i] = nvec[i];
	}
	delete[] nvec;
	return rez;

}
CHislo& CHislo::operator=(const CHislo& other)
{
	if (this != &other)
	{
		size = other.size;
		shared_ptr<int[]> cel(new int[size]);
		el = cel;
		for (size_t i = 0; i < size; i++)
		{
			el[i] = other.el[i];
		}
	}
	return *this;
}
ostream& operator<<(ostream& cout, CHislo& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		cout << other.el[i];
	}
	return cout;
}
int CHislo::Compare(const int* a, const int razm)
{
	int cntrl = 0;
	if (razm == size)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (a[i] == el[i])
				cntrl++;
		}
		if (cntrl == size)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}