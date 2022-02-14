#pragma once
#include <iostream>
#include <initializer_list>

using namespace std;

template <class T> class Polynomial
{

private:

	int size;  // size of coeff (degree = size - 1)
	T* coeff;   // array of coefficients of the polynomial (eg. {1, 2, 3} <=>1+2x+3x^2

public:

	Polynomial(vector<T> coefficients) : size(coefficients.size()) {
		coeff = new T[coefficients.size()];
		copy(coefficients.begin(), coefficients.end(), coeff);
	}

	Polynomial(int st, T* t = nullptr) :size(st + 1) {

		coeff = new T[st + 1];
		if (!t) {
			for (int i = 0; i < st + 1; i++)
				coeff[i] = 0;
		}
		else {
			for (int i = 0; i < st + 1; i++)
				coeff[i] = t[i];
		}
	}

	Polynomial() :size(0), coeff(nullptr) {}

	Polynomial(const Polynomial<T>& w) {
		size = w.size;
		coeff = new T[size];
		for (int i = 0; i < size; i++)
			coeff[i] = w[i];
	}

	~Polynomial()
	{
		delete coeff;
	}

	friend Polynomial<T> operator+(const Polynomial<T>& p1, const Polynomial<T>& p2) {
		Polynomial<T> out;
		if (p1.size >= p2.size) {
			out = Polynomial<T>(p1);
			for (int i = 0; i < p2.size; i++) {
				out[i] += p2[i];
			}
		}
		else {
			out = Polynomial<T>(p2);

			for (int i = 0; i < p1.size; i++) {
				out[i] += p1[i];
			}
		}
		return out;
	}

	friend Polynomial<T> operator-(const Polynomial<T>& p1, const Polynomial<T>& p2) {
		Polynomial<T> out;
		if (p1.size >= p2.size) {
			out = Polynomial<T>(p1);
			for (int i = 0; i < p2.size; i++) {
				out[i] -= p2[i];
			}
		}
		else {
			out = Polynomial<T>(p2);

			for (int i = 0; i < p1.size; i++) {
				out[i] -= p1[i];
			}
		}
		return out;
	}

	Polynomial<T>& operator=(const Polynomial<T>& p2)
	{
		if (coeff == p2.coeff)  return *this;
		if (size <= p2.size) {
			delete coeff;
			coeff = new T[p2.size];
			size = p2.size;
			for (int i = 0; i < p2.size; i++) {
				coeff[i] = p2.coeff[i];
			}
			size = p2.size;
		}
		else {
			delete  coeff;
			coeff = new T[p2.size];
			size = p2.size;
			for (int i = 0; i < p2.size; i++) {

				coeff[i] = p2.coeff[i];
			}
		}
		return *this;
	}

	friend Polynomial<T>& operator*(const Polynomial<T>& p1, const Polynomial<T>& p2) {
		Polynomial<T>* out = new Polynomial<T>((p1.size - 1) + (p2.size - 1));
		for (int i = 0; i < p1.size; i++) {
			for (int j = 0; j < p2.size; j++) {
				(*out)[i + j] += p1[i] * p2[j];
			}
		}
		return *out;
	}
	T operator()(T x) const {
		T s = coeff[size - 1];
		for (int i = 1; i < size; i++) {
			s *= x;
			s += coeff[size - 1 - i];
		}

		return s;
	}
	T operator[](int n) const
	{
		return coeff[n];
	}

	T& operator[](int n) {
		return coeff[n];
	}


	friend ostream& operator<<(ostream& os, const Polynomial& p)
	{
		for (int i = p.size - 1; i > 0; --i)
			os << p.coeff[i] << "*x^" << i << " + ";
		return os << p.coeff[0];
	}
};


