#pragma once
#include <iostream>
#include <math.h>
#include"IAP.h"
#include<sstream>

class Time
{
private:
	void checkMaxTime() {
		while (sec > 59) {
			min++;
			sec -= 60;
		}
		while (min > 59) {
			hours++;
			min -= 60;
		}
	}

	void checkMinTime() {
		while (sec < 0) {
			min--;
			sec += 60;
		}
		while (min < 0) {
			hours--;
			min += 60;
		}
	}

	int hours, min, sec;
public:
	Time(int hours, int min, int sec) { 
		setHours(hours);  // конструктор, который собирает время из функций
		setMin(min);
		setSec(sec);
	}

	Time() { hours = 0; min = 0; sec = 0; } // конструктор по умолчанию

	void setHours(int arg) {  // три функции ввода
		hours = arg;
	}

	void setMin(int arg) {
		if (arg < 0 || arg > 59) {
			throw string("Значение минут должно быть между 0 и 60"); // эксепшоны, если пользователь долбаёб
		}
		min = arg;
	}

	void setSec(int arg) {
		if (arg < 0 || arg > 59) {
			throw string("Значение секунд должно быть между 0 и 60");
		}
		sec = arg;
	}

	int getHours() {
		return hours;
	}

	int getMin() {
		return min;
	}

	int getSec() {
		return sec;
	}

	Time inputT() {
		int hours, min, sec;
		Time myTime;
		while (1) {
			input(hours, "Введите часы");
			input(min, "Введите минуты");
			input(sec, "Введите секунды");
			try {
				myTime = Time(hours, min, sec); // это попытка создать объект, если пользователь неправильно введёт время, будет эксепшон и он пойдёт нахуй, а объект не создастся
			}
			catch (string a) { // вывод эксепшона (текста, что пошло не так, переменная а это текст, который приходит из throw)
				output(a);
				clean();
				continue;
			}
			break;
		}
		return myTime;
	}

	void outputT() {
		stringstream sstr;
		sstr << hours << ':' << min << ':' << sec;
		output(sstr.str());
	}

	Time operator++() { // префиксный инкремент (++х)
		sec += 1;
		checkMaxTime();
		return *this;
	}

	Time operator++(int) { // постфиксный инкремент (х++)
		Time temp = *this;
		sec += 1;
		checkMaxTime();
		return temp;
	}

	Time operator--() { //префиксный декремент (--х)
		sec -= 1;
		checkMinTime();
		return *this;
	}

	Time operator--(int) { // постфиксный декремент (х--)
		Time temp = *this;
		sec -= 1;
		checkMinTime();		// префикс и постфикс различаются тем, что префиксный увеличивыет на один и возвращает прошлое значение, то есть если return х = ++0 то х станет = 1, а вернёт функция 0
		return temp;		// постфиксный наоборот, если return x = 0++, то х станет 1 и вернёт функция 1
	}

	Time operator-(int arg) {
		Time temp = *this;
		temp.sec -= arg;
		temp.checkMinTime();
		return temp;
	}

	Time operator-(Time& arg) {
		Time temp = *this;
		temp.sec -= arg.sec;
		temp.min -= arg.min;
		temp.hours -= arg.hours;
		temp.checkMinTime();
		return temp;
	}

	Time operator+(int arg) {
		Time temp = *this;
		temp.sec += arg;
		temp.checkMaxTime();
		return temp;
	}

	Time operator+(Time& arg) {
		Time temp = *this;
		temp.sec += arg.sec;
		temp.min += arg.min;
		temp.hours += arg.hours;
		temp.checkMaxTime();
		return temp;
	}

	Time operator*(int arg) {
		Time temp = *this;
		temp.sec *= arg;
		temp.min *= arg;
		temp.hours *= arg;
		temp.checkMaxTime();
		temp.checkMinTime();
		return temp;
	}
};

