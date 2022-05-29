#include "complex.h"
#include <iostream>

using namespace std;

int main() {
	complex<int> c1(2, 3);
	cout << c1 << endl;
	complex<int> c2(27, -200);
	cout << c2 << endl;
	complex<int> c3(-20, 4);
	cout << c3 << endl;
	complex<int> c4(-18, -99);
	cout << c4 << endl;
	cout << "c1 is"<< c1<< " and c2 is "<< c2<< "and c2 * c1 is " << c2 * c1 << endl;
	
	if (c1 == c2) {
		cout << "c1 equals c2" << endl;
	}
	else {
		cout << "c1 does not equal c2" << endl;
	}
	if (c1 != c2) {
		cout << "c1 does not equal c2" << endl;
	}
	else {
		cout << "c1 does equals c2" << endl;
	}

	complex<int>* c5 = new complex<int>(-200, -800);
	cout << *c5 << endl;
	delete c5;
	c1 = c2 = c3 = c4;
	//c1 = c2;
	cout << c3 << endl;
	return 0;

}