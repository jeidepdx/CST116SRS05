// main.cpp : Defines the entry point for the console application.
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

	unsigned TestYear{ InputYear1 }, TestMonth{ InputMonth1 }, TestDay{ InputDay1 };
	for (int i = 1; i <= 2; i++) // Loop to validate the values entered for InputDay1 and InputDay2
	{
		if (i == 2)
		{
			TestYear = InputYear2;
			TestMonth = InputMonth2;
			TestDay = InputDay2;
		}

		bool LeapYear = TestYear % 4 ? false : true;
		switch (TestMonth)
		{
		case KJan:
		case KMar:
		case KMay:
		case KJul:
		case KAug:
		case KOct:
		case KDec:
			assert(TestDay > 0 && TestDay <= 31);
			break;

		case KApr:
		case KJun:
		case KSep:
		case KNov:
			assert(TestDay > 0 && TestDay <= 30);
			break;

		case KFeb:
			if (LeapYear)
				assert(TestDay > 0 && TestDay <= 29);
			else if (!LeapYear)
				assert(TestDay > 0 && TestDay <= 28);
			break;

		default:
			assert(false);
			break;
		}
	}

	unsigned LowYear{ InputYear1 };
	unsigned LowMonth{ InputMonth1 };
	unsigned LowDay{ InputDay1 };
	unsigned HighYear{ InputYear2 };
	unsigned HighMonth{ InputMonth2 };
	unsigned HighDay{ InputDay2 };

	if (InputYear1 > InputYear2 || InputYear1 == InputYear2 && (InputMonth1 > InputMonth2 || InputMonth1 == InputMonth2 && InputDay1 > InputDay2))
	{
		LowYear = InputYear2;
		LowMonth = InputMonth2;
		LowDay = InputDay2;

		HighYear = InputYear1;
		HighMonth = InputMonth1;
		HighDay = InputDay1;
	}

	unsigned PrintYear{ LowYear };
	unsigned PrintMonth{ LowMonth };
	unsigned PrintDay{ LowDay };
	unsigned CurMoDays{ 0 };

	while (PrintYear != HighYear || PrintMonth != HighMonth || PrintDay != HighDay) // Loop to print out all dates from the low date to the high date.
	{
		if (CurMoDays == 0 || PrintDay == 1) // CurMoDays is 0 on the first run through the loop. PrintDay is 1 whenever a new month is started.
		{
			bool LeapYear = PrintYear % 4 ? false : true;
			switch (PrintMonth)
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
				if (LeapYear) CurMoDays = 29;
				else CurMoDays = 28;
				break;

			default:
				assert(false);
				break;
			}
		}

		std::cout << PrintYear << "-" << std::setfill('0') << std::setw(2) << PrintMonth << "-" << std::setw(2) << PrintDay << std::endl;

		if (CurMoDays < ++PrintDay) // after printing the last day of the month reset the day counter to 1.
		{
			PrintDay = 1;

			if (12 < ++PrintMonth) // after printing the last month of the year, reset month to 1 and increment the year count.
			{
				PrintMonth = 1;
				PrintYear++;
			}

		}
	}

	return 0;
}