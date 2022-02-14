#include <iostream>
#include <vector>
#include "polynomial.h"
#include <string>
#include <sstream>

using namespace std;

template <class T> Polynomial<T> enterPolynomial(Polynomial<T> p)
{
	cout << "Please, enter coeffficeints for polynomial: (eg. 1 2 3 <=> 1+2x+3x^2) \n";
	vector<double> coeff;
	string tmp;
	string line;
	getline(cin, line);
	std::istringstream iss(line);
	while (iss >> tmp) {
		coeff.push_back(strtod(tmp.c_str(), nullptr));
	}

	Polynomial<double> poly(coeff);
	cout << poly << "\n";

	return poly;
}
int main()
{
	Polynomial<double> poly1, poly2, * poly3 = new Polynomial<double>(0);

	double result = 0;
	while (true) {
		cout << "Hello to PolynomialCalcualtor!!!\n\n";
		cout << "Operations: \n+ - add two polynomials\n- - substract two polynomials" <<
			"\n* - muliplay two polynomials\ne - evaluating polynomial at 'some number'\n" <<
			"i - set current polynomial\nx - exit app\n";
		cout << "current polynomial: " << *poly3 << "\n";
		cout << "Chose operation: ";
		char op;
		cin >> op;
		switch (op)
		{
		case '+':
			getchar();
			poly1 = enterPolynomial(poly1);
			poly2 = enterPolynomial(poly2);
			*poly3 = poly1 + poly2;
			cout << "Polynomial 1: " << poly1 << "\n" << "Polynomial 2: " << poly2 << "\n";
			cout << *poly3 << "\n";
			break;
		case '-':
			getchar();
			poly1 = enterPolynomial(poly1);
			poly2 = enterPolynomial(poly2);
			*poly3 = poly1 - poly2;
			cout << "Polynomial 1: " << poly1 << "\n" << "Polynomial 2: " << poly2 << "\n";
			cout << *poly3 << "\n";
			break;
		case '*':
			getchar();
			poly1 = enterPolynomial(poly1);
			poly2 = enterPolynomial(poly2);
			*poly3 = poly1 * poly2;
			cout << "Polynomial 1: " << poly1 << "\n" << "Polynomial 2: " << poly2 << "\n";
			cout << *poly3 << "\n";
			break;
		case 'e':
			getchar();
			cout << "Enter x: ";
			double x;
			cin >> x;
			result = (*poly3)(x);
			cout << "(" << *poly3 << ")(" << x << ") = " << result << "\n";
			getchar();
			break;
		case 'i':
			getchar();
			*poly3 = enterPolynomial(poly1);
			break;
		case 'x':
			return 0;
		default:
			cout << "Invalid operation try again...\n";
			break;
		}
		getchar();
		system("CLS");

	}
	return 0;
}

