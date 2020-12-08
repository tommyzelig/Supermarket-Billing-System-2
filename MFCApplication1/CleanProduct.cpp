#include "pch.h"
#include "CleanProduct.h"

IMPLEMENT_SERIAL(CleanProduct, NonFood, 1);


CleanProduct::CleanProduct(const char * name, double price, bool isLocalManufacturer, bool isDangerus)
	: NonFood(name, price, isLocalManufacturer), isDangerus(isDangerus)
{

}

double CleanProduct::GetTotalPrice()
{
	double totalPrice = this->price;

	if (!isDangerus)
	{
		totalPrice *= 1.25;
	}

	if (!isLocalManufacturer) 
	{
		totalPrice *= 1.2;
	}

	return totalPrice;
}

void CleanProduct::SetDangerous(bool newMode)
{
	isDangerus = newMode;
}
