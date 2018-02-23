// DateList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>


int main()
{
	const unsigned KJan{ 1 };
	const unsigned KFeb{ 2 };
	const unsigned KMar{ 3 };
	const unsigned KApr{ 4 };
	const unsigned KMay{ 5 };
	const unsigned KJun{ 6 };
	const unsigned KJul{ 7 };
	const unsigned KAug{ 8 };
	const unsigned KSep{ 9 };
	const unsigned KOct{ 10 };
	const unsigned KNov{ 11 };
	const unsigned KDec{ 12 };

	unsigned InputYear1{};
	unsigned InputMonth1{};
	unsigned InputDay1{};
	unsigned InputYear2{};
	unsigned InputMonth2{};
	unsigned InputDay2{};

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

	bool LeapYear{ InputYear1 % 4 ? false:true};
	unsigned tmonth{ InputMonth1 }, tyear{ InputYear1 }, tday{InputDay1};
	for (int i = 1; i <= 2; i++)
	{
		if (i == 2)
		{
			tyear = InputYear2;
			tmonth = InputMonth2;
			tday = InputDay2;
		}
		switch (tmonth)
		{
		case KJan:
		case KMar:
		case KMay:
		case KJul:
		case KAug:
		case KOct:
		case KDec:
			assert(tday <= 31);
			break;

		case KApr:
		case KJun:
		case KSep:
		case KNov:
			assert(tday <= 30);
			break;

		case KFeb:
			if(i == 2) LeapYear = tyear % 4?false : true;
			if (LeapYear) assert(tday <= 29);
			else if (!LeapYear) assert(tday <= 28);
			break;

		default:
			assert(false);
			break;
		}
	}

	unsigned L_year{InputYear1};
	unsigned L_month{InputMonth1};
	unsigned L_day{InputDay1};
	unsigned H_year{ InputYear2 };
	unsigned H_month{ InputMonth2 };
	unsigned H_day{ InputDay2 };

	if (InputYear1 > InputYear2 || InputYear1 == InputYear2 && (InputMonth1 > InputMonth2 || InputMonth1 == InputMonth2 && InputDay1 > InputDay2))
	{
		L_year = InputYear2;
		L_month = InputMonth2;
		L_day = InputDay2;

		H_year = InputYear1;
		H_month = InputMonth1;
		H_day = InputDay1;
	}

	unsigned pyear{ L_year };
	unsigned pmonth{ L_month };
	unsigned pday{ L_day };
	unsigned CurMoDays{};
	bool InitNewMonth{ true };

	while (pyear != H_year || pmonth != H_month || pday != H_day)
	{
		std::cout << pyear << "-" << std::setfill('0') << std::setw(2) << pmonth << "-" << std::setw(2) << pday << std::endl;

		if (InitNewMonth)
		{
			switch (pmonth)
			{
			case KJan:
			case KMar:
			case KMay:
			case KJul:
			case KAug:
			case KOct:
			case KDec:
				CurMoDays = 31;
				break;

			case KApr:
			case KJun:
			case KSep:
			case KNov:
				CurMoDays = 30;
				break;

			case KFeb:
				LeapYear = pyear % 4 ? false : true;
				if (LeapYear) CurMoDays = 29;
				else CurMoDays = 28;
				break;

			default:
				assert(false);
				break;
			}

			InitNewMonth = false;
		}

		if (CurMoDays < ++pday)
		{
			pday = 1;
			InitNewMonth = true;

			if (12 < ++pmonth)
			{
				pmonth = 1;
				pyear++;
			}

		}
	}

	return 0;
}

