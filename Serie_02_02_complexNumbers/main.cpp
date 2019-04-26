#include "complex.h"

using namespace std;

int main()
{
	Complex c1(1,2), c2(3,4), c3;

	cout << "c1 = ";
	c1.show();

	cout << "c2 = ";
	c2.show();

	c3 = c1.add(c2);

	cout << "c3 = c1 + c2 = ";
	c3.show();

	cout << "Real part of c3 : "<< c3.getReal() << endl;
	cout << "Imaginary part of c3 : "<< c3.getImaginary() << endl;

	return 0;
}
