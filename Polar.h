#pragma once
#include"IAP.h"
#include<iostream>
#include<math.h>
#include<sstream>

class Decart; // ёбнутая ебанина, вроде бы задание простое, но тк я хотел блять улучшить, я себе хуй в жопу засунул

class Polar
{
private:
	double angle, R;
public:
	Polar(double angle, double R) : angle(angle), R(R) { // конструктор, в который засовывыется угол и радиус
		if (angle > 360) {
			throw string("Выход за пределы максимума значения угла\n");
		}
		if (R < 0) {
			throw string("Отрицательное значение радиуса\n");
		}
	}

	Decart toDecart(); // декларация функции, декларация говорит программе о том, что функция где то есть, но не тут)))

	string toStr() {
		stringstream sstr;
		sstr << angle << " " << R;
		return sstr.str();
	}

	Polar operator+(Polar);
};

class Decart
{
private:
	double x, y;
public:
	Decart(double x, double y) : x(x), y(y) {}

	Polar toPolar(); // декларация (см. Polar.cpp)

	string toStr() {
		stringstream sstr;
		sstr << x << " " << y;
		return sstr.str();
	}

	Decart operator+(Decart);
};

