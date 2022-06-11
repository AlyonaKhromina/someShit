#pragma once
#include"IAP.h"

class Fraction
{
private:
	int chisl, znam;
public:
	Fraction() : chisl(0), znam(0) {}
	Fraction(int i, int j) : chisl(i), znam(j) {}


	Fraction Inputf()
	{
		Fraction fraction;
		input(fraction.chisl, "Введите числитель дроби");
		input(fraction.znam, "Введите знаменатель дроби");
		return fraction;
	}

	Fraction sum(int chisl, int znam)
	{
		Fraction fraction;
		fraction.chisl = (chisl * znam) + (znam * chisl);
		fraction.znam = znam * znam;
		return fraction;
	}

	Fraction operator+(Fraction& fraction)
	{
		return sum(fraction.chisl, fraction.znam);
	}

	Fraction minus(int chisl, int znam) {
		Fraction fraction;
		fraction.chisl = (chisl * znam) - (znam * chisl);
		fraction.znam = znam * znam;
		return fraction;
	}

	Fraction operator-(Fraction& fraction) {
		return minus(fraction.chisl, fraction.znam);
	}

	Fraction Multiply(int chisl, int znam) {
		Fraction fraction;
		fraction.chisl = chisl * chisl;
		fraction.znam = znam * znam;
		return fraction;
	}

	Fraction operator*(Fraction& fraction) {
		return Multiply(fraction.chisl, fraction.znam);
	}


	Fraction div(int chisl, int znam) {
		Fraction fraction;
		fraction.chisl = chisl * znam;
		fraction.znam = znam * chisl;
		return fraction;
	}

	Fraction operator/(Fraction& fraction) {
		return div(fraction.chisl, fraction.znam);
	}

	bool operator==(Fraction& fraction) {  // На сравнении препод мне сделал замечания, потому что я использовал Cut для сравнения дробей, я не помню, как он говорил лучше сделать, поэтому сделал как то так, если приебётся, я оставил с Cut, в комментах
		double num1, num2;
		num1 = double(this->chisl / this->znam);
		num2 = double(fraction.chisl / fraction.znam);
		return num1 == num2;
		//return this->Cut().chisl == fraction.Cut().chisl && this->Cut().znam == this->Cut().znam;
	}

	bool operator!=(Fraction& fraction) {
		double num1, num2;
		num1 = double(this->chisl / this->znam);
		num2 = double(fraction.chisl / fraction.znam);
		return num1 != num2;
		//return this->Cut().chisl != fraction.Cut().chisl && this->Cut().znam != this->Cut().znam;;
	}

	void print()
	{
		cout << chisl << "/" << znam << endl;
	}

	Fraction Cut() {
		for (int counter = 2; counter <= chisl; counter++) {
			if (chisl % counter == 0 && znam % counter == 0) {
				chisl = chisl / counter;
				znam = znam / counter;
				counter = 2;
			}
		}
		return *this;
	}
};

