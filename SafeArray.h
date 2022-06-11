#pragma once
#include"IAP.h"
#include<iostream>

const int max_array_size = 100;

class SafeArray {
	int maxB, minB;
	int limit[max_array_size];
public:
	SafeArray(int min_bound, int max_bound, int init_value) { // туточки всё просто, оставляем safeArray из прошлой лабы
		if (min_bound < 0) {
			throw string("Нижняя граница меньше 0\n");
		}
		if (max_bound < min_bound) {
			throw string("Верхняя граница меньше нижней\n"); // это конструктор, тут проверяется, нормально ли пользователь ввёл границы
		}
		if (max_bound - min_bound > max_array_size) {
			throw string("Массив не может содержать больше 100 элементов\n"); // throw это если что эксепшоны(исключения), если препод спросит, просто скажи, что это 
		}																	  // экспешон они служат для обработки каких либо ошибок, например, если в массиве 10 элементов, а ты хочешь запосить 15й, 
																			  // то программа крашнется, а если сделать эксепшон, то программа сделает, что указано в коде, внашем случае напишет, что пользоваель долбаёб
		maxB = max_bound;
		minB = min_bound;
		for (int counter = 0; counter < maxB - minB; ++counter) // в массив засовывается числа, просто, чтобы были
			limit[counter] = init_value + counter;
	}

	int operator[](int index) { // и добавляем к нему оператор 
		if (index >= maxB || index < minB) { // проверка на то, что пользователь не нахерил ничего с границами
			throw string("Выход за пределы массива\n");
		}
		return limit[index - minB]; //  а тут вывод, по заданию в массиве 100 элементов, но можно вызвать 175й элемент, сделав начало массива на 100 элементов и конец на 200, надеюсь, ты понял
	}
};


