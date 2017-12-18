#include "Card.h"
int PenaltyFee(Time esReturn, Time realReturn){
	// Initiating variables : daysover(days over rules), fee(money for paying), distance1(between 2 returning time),
	int daysover, distance1, distance2;
	int fee = 0;
	// In-condition : estimatedYear = returningYear, estimatedMonth = returningMonth
	if (esReturn.year == realReturn.year) // Same year
	{
		if (esReturn.month == realReturn.month)  // Same month
		{
			if (esReturn.day >= realReturn.day) return 0;
			else
			{
			daysover = realReturn.day - esReturn.day;
			fee = daysover * 5000;
				return fee;
			}
		}
		// In-condition: estimatedMonth != returningMonth
		else if (esReturn.month < realReturn.month)
		{
			// If estimatedMonth = 2
			if (esReturn.month == 2)
			{
				// Check if leap year
				if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)
				{
					// Caculating distance from	returningDay of returningMonth to estimatedDay of estimatedMonth
					distance1 = realReturn.day;
					int i = realReturn.month - 1;
					for (i; i > esReturn.month; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 = distance1 + 31;
						else distance1 = distance1 + 30;
					}
					// Nam nhuan nen so ngay qua han bang distance + (29 - estimatedDay)
					daysover = distance1 + (29 - esReturn.day);
					fee = 5000 * daysover;
					return fee;
				}
				else // Not a leap year
				{
					distance1 = realReturn.day;
					int i = realReturn.month - 1;
					for (i; i > esReturn.month; i--)
					{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
						else distance1 += 30;
					}
					// Nam khong nhuan nen so ngay qua han bang distance + (28-estimatedDay)
					daysover = distance1 + (28 - esReturn.day);
					fee = 5000 * daysover;
				return fee;
				}
			}
			else //estimatedMonth != 2
			{
				// if returning month in 1,3,5,7,8,10,12 which has 31 days
				if (esReturn.month == 1 || esReturn.month == 3 || esReturn.month == 5 || esReturn.month == 7 || esReturn.month == 8 || esReturn.month == 10 || esReturn.month == 12)
				{
					// Check if leap year
					if ((esReturn.year % 4 == 0 && esReturn.year % 100 != 0) || esReturn.year % 400 == 0)
					{
						distance1 = realReturn.day;
						int i = realReturn.month - 1;
						for (i; i > esReturn.month; i--)
						{
						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 29;
							else distance1 += 30;
						}
						daysover = distance1 + (31 - esReturn.day);
						fee = 5000 * daysover;
						return fee;
					}
					else // not a leap year
					{
						distance1 = returningDay;
						int i = returningMonth - 1; // check next month
						for (i; i > estimatedMonth; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 28;
							else distance1 += 30;
						}
						daysover = distance1 + (31 - estimatedDay);
						fee = daysover * 5000;
						return fee;
					}
				}
				else // if in month 4,6,9,11  which has 30 days
				{
					if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)
					{
						distance1 = returningDay;
						int i = returningMonth - 1;
						for (i; i > estimatedMonth; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 29;
							else distance1 += 30;
						}
						daysover = distance1 + (30 - estimatedDay);
						fee = 5000 * daysover;
						return fee;
					}
					else // not leap year
					{
						distance1 = returningDay;
						int i = returningMonth - 1;
						for (i; i > estimatedMonth; i--)
						{
							if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance1 += 31;
							else if (i == 2) distance1 += 28;
							else distance1 += 30;
						}
						daysover = distance1 + (30 - estimatedDay);
						fee = 5000 * daysover;
						return fee;
					}
				}
			}
		}
		return fee;
	}
	else// In-condition : estimatedYear < returningYear
	{
		distance2 = 0;
		// calculating distance from estimatedDay, estimatedMonth to 31/12/estimatedYear.
		if (estimatedMonth == 2) // if estimatedMonth = 2
		{
			//check leap year

			if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)

			{

				// calculating distance from returningDay of returningMonth to estimatedDay of estimatedMonth

				int i = estimatedMonth + 1;

				for (i; i <= 12; i++)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

					else if (i == 2) distance2 += 29;

					else distance2 += 30;

				}

				daysover = distance2 + (29 - estimatedDay);

			}

			else // not a leap year

			{

				int i = estimatedMonth + 1;

				for (i; i <= 12; i++)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

					else if (i == 2) distance2 += 28;

					else distance2 += 30;

				}

				daysover = distance2 + (28 - estimatedDay);

			}

		}

		else // if estimatedMonth != 2

		{

			// if estimatedmonth in 1,3,5,7,8,10,12

			if (estimatedMonth == 1 || estimatedMonth == 3 || estimatedMonth == 5 || estimatedMonth == 7 || estimatedMonth == 8 || estimatedMonth == 10 || estimatedMonth == 12)

			{

				// check leap year

				if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)

				{

					int i = estimatedMonth + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 29;

						else distance2 += 30;

					}

					daysover = distance2 + (31 - estimatedDay);

				}

				else // not a leap year

				{

					int i = estimatedMonth + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 28;

						else distance2 += 30;

					}

					daysover = distance2 + (31 - estimatedDay);

				}

			}

			else // estimatedmonth in 4,6,9,11

			{

				// check leap year

				if ((estimatedYear % 4 == 0 && estimatedYear % 100 != 0) || estimatedYear % 400 == 0)

				{

					int i = estimatedMonth + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 29;

						else distance2 += 30;

					}

					daysover = distance2 + (30 - estimatedDay);

				}

				else //not a leap year

				{

					int i = estimatedMonth + 1;

					for (i; i <= 12; i++)

					{

						if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) distance2 += 31;

						else if (i == 2) distance2 += 28;

						else distance2 += 30;

					}

					daysover = distance2 + (30 - estimatedDay);

				}

			}

		}

		// calculating distance from 1/1/returningYear to returningDay/returningMonth/returningYear

		int daysover2 = 0;

		// check leap year

		if ((returningYear % 4 == 0 && returningYear % 100 != 0) || returningYear % 400 == 0)

		{

			if (returningMonth == 1) daysover2 = returningDay; // Jan

			else if (returningMonth == 2) daysover2 = 31 + returningDay; // Feb 

			else // all except Jan, Feb

			{

				daysover2 = returningDay;

				int i = returningMonth - 1;

				for (i; i > 0; i--)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysover2 += 31;

					else if (i == 2) daysover2 += 29;

					else daysover2 += 30;

				}

			}

		}

		else // not a leap year

		{

			if (returningMonth == 1) daysover2 = returningDay;

			else if (returningMonth == 2) daysover2 = 31 + returningDay;

			else // except Jan, Feb

			{

				daysover2 = returningDay;

				int i = returningMonth - 1;

				for (i; i > 0; i--)

				{

					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) daysover2 += 31;

					else if (i == 2) daysover2 += 28;

					else daysover2 += 30;

				}

			}

		}

		// calculating  days between estimatedYear -> returningYear

		int daysover3 = 0;

		for (int i = returningYear; i > estimatedYear; i--)

		{

			// if leap year

			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) daysover3 += 366;

			else daysover3 += 365;

		}

		// Total days over :

		int totaldaysover = daysover + daysover2 + daysover3;

		fee = 5000 * totaldaysover;

		return fee;

	}


}