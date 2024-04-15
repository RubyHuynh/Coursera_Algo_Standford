#include<iostream>
#include<ostream>
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long TYPE;

int karatsuba(TYPE a, TYPE b) {
	TYPE digits;
	TYPE leftA, rightA, leftB, rightB;
	TYPE x1, x2, x3;

	std::cout << "\t" << a << "*" << b  << "\n";
	if (a < 10 || b < 10) {
		return a*b;
	}
	std::string aStr = to_string(a);
	std::string bStr = to_string(b);
	digits = std::max(aStr.length(), bStr.length());
	
	TYPE half  = digits/2;

	leftA = stoi(aStr.substr(0, half));
	rightA = stoi(aStr.substr(half, digits-half));
	leftB = stoi(bStr.substr(0, half));
	rightB = stoi(bStr.substr(half, digits-half));

	x1 = karatsuba(leftA, leftB);
	x2 = karatsuba(rightA, rightB);
	x3 = karatsuba(leftA + rightA, leftB + rightB);
	
	return x1 * std::pow(10, 2*half) + (x3 -x2 -x1)*std::pow(10, half) + x2;
}


int main() {
	std::cout << karatsuba(15, 10) << "\n";
	return 0;
}
