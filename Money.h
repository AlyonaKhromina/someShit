#pragma once
#include"IAP.h"
#include<iostream>
#include<sstream>
#include<iomanip>


class Money {
private:
	string moneyStr;
	char c;
public:
	long double num;

	void moneyInput() {
		moneyStr = input(moneyStr, "Введите значиение: ");
	}

	double toDouble() {  // честно говоря, я сам хз, что делают функции toDouble и toStr, они запутанные, даже читать их не хочу, они были в прошлой лабе, если приебётся, скажи, что спиздил у меня в прошлой лабе, а потом юзнул здесь
		int firstCheck; // в целом, он говорил, что всё ок, если спиздил код, главное его объяснить
		int count = 1; // бля, ок, ладно, мне придётся разобраться, чтобы написать комментарии, чтобы ты мог объяснить, что тут проиходит
		string buf;
		int temp = 0;
		int pointIndex;
		string s = ""; // создаётся пустая строка
		for (int y = 0; y < moneyStr.length(); y++) { // далее посимвольно читаем строку, помешяем символ в строку buf
			buf = moneyStr[y];
			if (buf != "," and buf != "$") { // далее идёт проверка, ведь нам надо избавиться от не нужных символов и оставить только число
				s += buf;
			}
			else
				temp++;
		}
		stringstream sstr; // создаём стрингстрим, его фишка в том, что в него можно сувать символы и строки любого типа, например, туда можно сунуть, как string, так и int
		sstr << s; // cуём строку
		sstr >> num; // и мальчика я превращаю в зайчика! из string получается double 
		return num;
	}

	string toStr() { // ох, блеадь, ебаться в пассатижи, эта функция выглядит ещё более уёбищно
		stringstream sstr;
		stringstream answer; // окееееюшки, тут два стрингстрима, пока хз, зачем они, но ща разберёмся
		string strPart = "";
		answer << "$"; // первый символ в выводе должен быть знак доллара
		string strMoney;
		bool in_begin = true; // это переменная проверяет, находимся ли мы в начале строки, пока хз, зачем она, но она нужна 
		string buf;
		sstr << this->num; // пихаем в стригстрим наше число
		//for (int counter = 0; counter < strMoney.length(); counter++) { // тут по символам перебираем строку strMoney 
		//	buf = strMoney[counter];
		//	if (buf == "0" && in_begin == true) { ОК Я НЕ ПОНЯЛ ЭТОГО ШАМАНСТВА, НО КАК Я ПОСМОТРЕЛ, STRMONEY ПУСТОЙ, ЗНАЧИТ ЦИКЛ ВООБЩЕ НЕ РАБОТАЕТ, ОН ТАК ТО ДОЛЖЕН УБИРАТЬ НУЛИ В НАЧАЛЕ СТРОКИ, НО ВСЁ ПОЧЕМУ ТО РАБОТАЕТ БЕЗ НЕГО
		//		continue;          Можешь его удалить))))))))))))))))
		//	}
		//	else {
		//		in_begin = false;
		//		sstr << strMoney[counter];  Забавный рудимент)
		//	}								Я решил оставить это и не удалять, чтобы ты тоже поржал)
		//}
		strMoney = sstr.str(); 
		int value = 0;
		for (int count = 0; count < strMoney.length(); count++) { // тут добавляем запятые, работает это криво, но препод схавал
			answer << strMoney[count];
			value += 1;
			if (value == 3 && strMoney[count + 1] != '\0') {
				value = 0;
				answer << ",";
			}
		}
		return answer.str(); // cпасибо за внимание нахуй!
	}

	string operator+(Money& other) {
		Money answer;
		answer.num = this->toDouble() + other.toDouble();
		return answer.toStr();
	}

	string operator-(Money& other) {
		Money answer;
		answer.num = this->toDouble() - other.toDouble();
		return answer.toStr();
	}

	string operator*(Money& other) {
		Money answer;
		answer.num = this->toDouble() * other.toDouble();
		return answer.toStr();
	}

	string operator/(Money& other) {
		Money answer;
		answer.num = this->toDouble() / other.toDouble();
		return answer.toStr();
	}
};

