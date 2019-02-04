#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
class matrix
{
public:
	matrix();
	matrix(size_t, size_t, int**);
	matrix(size_t, size_t);
	matrix(const matrix&);
	const matrix& operator=(const matrix&);
	~matrix();
	matrix operator*(const matrix&) const;
	matrix operator+(const matrix&) const;
	matrix operator*(int) const;

	friend matrix operator*(int, const matrix&);
	friend std::ostream& operator<<(std::ostream&, const matrix&);

private:
	LinkedList<int> * element;
	size_t rows, columns;
};