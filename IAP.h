#pragma once
#include <iostream>
using namespace std;

void output(string myOutput) {
	cout << myOutput << endl;
}
void output(int myOutput) {
	cout << myOutput << endl;
}
void output(double myOutput) {
	cout << myOutput << endl;
}
void output(float myOutput) {
	cout << myOutput << endl;
}

int input(int& myInput, string description) {
	output(description);
	cin >> myInput;
	return myInput;
}
float input(float& myInput, string description) {
	output(description);
	cin >> myInput;
	return myInput;
}

double input(double& myInput, string description) {
	output(description);
	cin >> myInput;
	return myInput;
}

char input(char& myInput, string description) {
	output(description);
	cin >> myInput;
	return myInput;
}
string input(string& myInput, string description) {
	output(description);
	cin >> myInput;
	return myInput;
}

void clean()
{
	system("pause");
	system("cls");
}
