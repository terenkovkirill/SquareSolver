/*!
\"C:\Users\KirillT\Desktop\SquareSolver\Head_Tests1.h"
\brief ������������ ���� � ��������� �������

������ ���� �������� � ���� ����������� ��������
�������, ������������ � ���������������� ���������
*/


#ifndef TESTS1_H
#define TESTS1_H
#include <stdio.h>
#include "Head_Solving1.h"

/// ���������, ���������� �������� ������

struct CheckData
{
    double a, b, c;                 ///< a, b, c - ������������ ����������� ��������� ax**2 + bx + c
    double x1Expected, x2Expected;  ///< x1Expected, x2Expected - ���������� ����� ����������� ��������� � ��������� ��������������
    int nRootsExpected, nTest;      ///< nRootsExpected - ���������� ����� ������, nTest - ����� �����
};




///@brief: ������� ��������� ����� � ��������� ������������ ������ ���������

///@param: CheckData - ���������, ���������� �������� ������

///@details: ������� �������� SolveSquare � ��������� ����� �� \
             ���������� ���������� ������, ������� �����

void RunTest (const struct CheckData *test);




///@brief: ������� ���������� ������

///@file: test_file - ��������� ���� � ��������� �������

///@param: CheckData - ���������, ���������� �������� ������

///@details: ������� ��������� �������� ������ �� ����� ������������\
           � �������� ������� RunTest ��� �������� ������������ ������ ���������

void CheckAllTests();


#endif
