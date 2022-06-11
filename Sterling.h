#pragma once
#include"IAP.h"
#include<sstream>
#include<iostream>
// ВНИМАЕНИЕ, АНЕКДОТ! Пошли как то с другом эпилептиком на вечеринку, получилась пенная вечеринка

class Sterling
{
private:
	int funt, shilling, pens;
public:
	Sterling() : funt(0), shilling(0), pens(0) {}
	Sterling(int f, int s, int p) : funt(f), shilling(s), pens(p) {}

	void checkM() { // эта и функция ниже пересчитывет пенсы и шиллинги, если их больше, чем надо
		while (pens > 11) {
			shilling++;
			pens -= 12;
		}
		while (shilling > 19) {
			funt++;
			shilling -= 20;
		}
	}

	void checkMin() {
		while (pens < 0) {
			shilling--;
			pens += 11;
		}
		while (shilling < 0) {
			funt--;
			shilling += 19;
		}
	}

	void getSterling() {
		input(funt, "Введите количество футнтов: ");
		input(shilling, "Введите количесво шиллингов: ");
		input(pens, "Введите количество пенсов: ");
		checkM();
		checkMin();
	}

	Sterling operator+(Sterling& other) {
		this->funt += other.funt;
		this->shilling += other.shilling;
		this->pens += other.pens;
		checkM();
		return *this;
	}

	Sterling operator-(Sterling& other) {
		this->funt -= other.funt;
		this->shilling -= other.shilling;
		this->pens -= other.pens;
		checkMin();
		return *this;
	}

	Sterling operator/(double& other) {
		this->funt /= other;
		this->shilling /= other;
		this->pens /= other;
		checkMin();
		checkM();
		return *this;
	}

	Sterling operator/(Sterling& other) {
		this->funt /= other.funt;
		this->shilling /= other.shilling; //? хуй знает, зачем этот вопросик, я его ставил, когда кодил, ну в целом, пусть будет тут
		this->pens /= other.pens;
		checkMin();
		checkM();
		return *this;
	}

	Sterling operator*(double& other) {
		this->funt *= other;
		this->shilling *= other;
		this->pens *= other;
		checkMin();
		checkM();
		return *this;
	}

	double toMoney() {
		return (double(funt) + (double(shilling) * 5.0 / 100.0) + (double(pens) * (100.0 / 12) / 1000.0)) * 50;
	}

	operator double() {
		return double(funt) + (double(shilling) * 5.0 / 100.0) + (double(pens) * (100.0 / 12) / 1000.0);
	}
};

