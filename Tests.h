/*!
\"C:\Users\KirillT\Desktop\SquareSolver\Head_Tests1.h"
\brief Çàãîëîâî÷íûé ôàéë ñ îïèñàíèåì êëàññîâ

Äàííûé ôàéë ñîäåðæèò â ñåáå îïðåäåëåíèÿ îñíîâíûõ
êëàññîâ, èñïîëüçóåìûõ â äåìîíñòðàöèîííîé ïðîãðàììå
*/


#ifndef TESTS1_H
#define TESTS1_H
#include <stdio.h>
#include "Head_Solving1.h"

/// Ñòðóêòóðà, ñîäåðæàùàÿ òåñòîâûå äàííûå
struct CheckData
{
    double a, b, c;                 ///< a, b, c - êîýôôèöèåíòû êâàäðàòíîãî óðàâíåíèÿ ax**2 + bx + c
    double x1Expected, x2Expected;  ///< x1Expected, x2Expected - êîððåêòíûå êîðíè êâàäðàòíîãî óðàâíåíèÿ ñ çàäàííûìè êîýôôèöèåíòàìè
    int nRootsExpected, nTest;      ///< nRootsExpected - êîððåêòíîå ÷èñëî êîðíåé, nTest - íîìåð òåñòà
};




///@brief: ôóíêöèÿ çàïóñêàåò òåñòû è ïðîâåðÿåò êîððåêòíîñòü ðàáîòû ïðîãðàììû

///@param: CheckData - ñòðóêòóðà, ñîäåðæàùàÿ òåñòîâûå äàííûå

///@details: ôóíêöèÿ âûçûâàåò SolveSquare è ïðîâåðÿåò âåðíû ëè \
             ïîëó÷åííûå ïðîãðàììîé îòâåòû, âûâîäèò îòâåò

void RunTest (const struct CheckData *test);




///@brief: ôóíêöèÿ ñ÷èòûâàíèÿ òåñòîâ

///@file: test_file - òåêñòîâûé ôàéë ñ òåñòîâûìè äàííûìè

///@param: CheckData - ñòðóêòóðà, ñîäåðæàùàÿ òåñòîâûå äàííûå

///@details: ôóíêöèÿ ñ÷èòûâàåò òåñòîâûå äàííûå èç ôàéëà ïîëüçîâàòåëÿ\
           è âûçûâàåò ôóíêöèþ RunTest äëÿ ïðîâåðêè êîððåêòíîñòè ðàáîòû ïðîãðàììû

void CheckAllTests();


#endif
