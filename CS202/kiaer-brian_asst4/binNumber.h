#include <iostream>
#include <string>
using namespace std;

class binNumber
{
public:
	binNumber();
	binNumber(string);
	binNumber& operator=(string);
	binNumber operator+(const binNumber&) const;
	binNumber operator+(string) const;
	binNumber operator-(const binNumber&) const;
	binNumber operator-(string) const;
	
	bool operator==(const binNumber&) const;
	bool operator!=(const binNumber&) const;
	bool operator<(const binNumber&) const;
	bool operator>(const binNumber&) const;
	bool operator<=(const binNumber&) const;
	bool operator>=(const binNumber&) const;

	friend binNumber operator+(string, const binNumber&);
	friend binNumber operator-(string, const binNumber&);
	friend ostream& operator<<(ostream&, const binNumber&);
	
private:
	string numString;
};