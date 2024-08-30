/*!
\"C:\Users\KirillT\Desktop\SquareSolver\Head_Tests1.h"
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных
классов, используемых в демонстрационной программе
*/


#ifndef TESTS1_H
#define TESTS1_H
#include <stdio.h>
#include "Solving.h"

/// Структура, содержащая тестовые данные

struct CheckData
{
    double a, b, c;                 ///< a, b, c - коэффициенты квадратного уравнения ax**2 + bx + c
    double x1Expected, x2Expected;  ///< x1Expected, x2Expected - корректные корни квадратного уравнения с заданными коэффициентами
    int nRootsExpected, nTest;      ///< nRootsExpected - корректное число корней, nTest - номер теста
};




///@brief: функция запускает тесты и проверяет корректность работы программы

///@param: CheckData - структура, содержащая тестовые данные

///@details: функция вызывает SolveSquare и проверяет верны ли \
             полученные программой ответы, выводит ответ

void RunTest (const struct CheckData *test);




///@brief: функция считывания тестов

///@file: test_file - текстовый файл с тестовыми данными

///@param: CheckData - структура, содержащая тестовые данные

///@details: функция считывает тестовые данные из файла пользователя\
           и вызывает функцию RunTest для проверки корректности работы программы

void CheckAllTests();


#endif
