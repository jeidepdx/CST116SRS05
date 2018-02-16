// DateList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>


int main()
{
	const int DaysJan{ 31 };
	const int DaysFebStd{ 28 };
	const int DaysFebLeap{ 29 };
	const int DaysMar{ 31 };
	const int DaysApr{ 30 };
	const int DaysMay{ 31 };
	const int DaysJun{ 30 };
	const int DaysJul{ 31 };
	const int DaysAug{ 31 };
	const int DaysSep{ 30 };
	const int DaysOct{ 31 };
	const int DaysNov{ 30 };
	const int DaysDec{ 31 };

	int InputYear1{};
	int InputMonth1{};
	int InputDay1{};
	int InputYear2{};
	int InputMonth2{};
	int InputDay2{};

	int H_year{};
	int H_month{};
	int H_day{};

	int L_year{};
	int L_month{};
	int L_day{};
	
	bool LeapYear{};

	std::cin >> InputYear1;
	std::cin.ignore();
	std::cin >> InputMonth1;
	std::cin.ignore();
	std::cin >> InputDay1;

	std::cin >> InputYear2;
	std::cin.ignore();
	std::cin >> InputMonth2;
	std::cin.ignore();
	std::cin >> InputDay2;

	assert(InputYear1 >= 1901 && InputYear1 <= 2099);
	assert(InputYear2 >= 1901 && InputYear2 <= 2099);
	assert(InputMonth1 > 0 && InputMonth1 <= 12);
	assert(InputMonth2 > 0 && InputMonth2 <= 12);

	int tmonth{ InputMonth1 }, tyear{InputYear1};
	for (int i = 0; i <= 1; i++)
		if (i != 0)
		{
			tyear = InputYear2;
			tmonth = InputMonth2;
		}
	switch (tmonth)
	{
	case 2:
		LeapYear = (tyear % 4 == 0);
		if (LeapYear) 
			assert(InputDay1 <= 29);
		else 
			assert(InputDay1 <= 28);
		break;
	default:
		if (((InputMonth1 % 2 == 0) && (InputMonth1 >= 8)) || ((InputMonth1 % 2 != 0) && (InputMonth1 <= 7)))
			assert(InputDay1 <= 31);
		else
			assert(InputDay1 <= 30);
		break;
	}

	bool A{ InputYear1 < InputYear2 };
	bool B{ InputYear1 == InputYear2 };
	bool C{ InputMonth1 < InputMonth2 };
	bool D{ InputMonth1 == InputMonth2 };
	bool E{ InputDay1 <= InputDay2 };

	if (A + B * C + B * D * E)
	{
		L_year = InputYear1;
		L_month = InputMonth1;
		L_day = InputDay1;

		H_year = InputYear2;
		H_month = InputMonth2;
		H_day = InputDay2;
	}
	else
	{
		L_year = InputYear2;
		L_month = InputMonth2;
		L_day = InputDay2;

		H_year = InputYear1;
		H_month = InputMonth1;
		H_day = InputDay1;
	}

	std::cout << "Lowest Date :" << L_year << "-";
	
	if (L_month < 10) std::cout << "0";
	std::cout << L_month << "-";
	
	if (L_day < 10) std::cout << "0";
	std::cout << L_day << std::endl;

	std::cout << "Highest Date :" << H_year << "-";

	if (H_month < 10) std::cout << "0";
	std::cout << H_month << "-";

	if (H_day < 10) std::cout << "0";
	std::cout << H_day << std::endl;

    return 0;
}

