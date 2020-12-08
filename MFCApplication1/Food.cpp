#include "pch.h"
#include "Food.h"

IMPLEMENT_SERIAL(Food, CObject, 1);

double Food::GetTotalPrice()
{
	double totalPrice = 0;
	totalPrice += price;


	if (isDairy)
	{
		if (isHot)
		{
			totalPrice += 10;
		}
	}
	else
	{
		if (isHot)
		{
			totalPrice += 50;
		}
	}


	return totalPrice;
}

void Food::SetIsHot(bool newMode)
{
	isHot = newMode;
}

Food::Food()
{

}

Food::Food(const char * name, double price, bool isHot, bool isDairy)
	: Product(name, price), isHot(isHot), isDairy(isDairy)
{

}
