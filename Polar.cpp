#include "Polar.h"
#define PI 3.14159265 
 

Polar Decart::toPolar() {
	double R = sqrt(pow(x, 2) + pow(y, 2));
	double angle = asin(x / R) * 180 / PI;
	return Polar(angle, R);
}

Decart Polar::toDecart() {
	return Decart(sin(angle * PI / 180) * R, cos(angle * PI / 180) * R);
}

Polar Polar::operator+(Polar other) {
	return (this->toDecart() + other.toDecart()).toPolar();
}

Decart Decart::operator+(Decart other) {
	return Decart(this->x + other.x, this->y + other.y);
}

// ну а тут просто использованы нереальные математические формулы, как бы да
