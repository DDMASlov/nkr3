#include "fl.hpp"
class CHislo
{
private:
	shared_ptr<int[]> el;
	size_t size;
public:
	CHislo();
	CHislo(const int* a, size_t b);
	CHislo(const CHislo& obj);
	~CHislo() = default;
	CHislo operator+(const CHislo& other);
	CHislo operator-(const CHislo& other);
	CHislo& operator=(const CHislo& other) = default;
	friend ostream& operator<<(ostream& cout, CHislo& other);
	int Compare(const int* a, const int razm);
};