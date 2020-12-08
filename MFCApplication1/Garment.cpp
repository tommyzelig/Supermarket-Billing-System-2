#include "pch.h"
#include "Garment.h"

IMPLEMENT_SERIAL(Garment, NonFood, 1);


Garment::Garment(const char * name, double price, bool isLocalManufacturer, int age, int size)
	: NonFood(name, price, isLocalManufacturer), age(age), size(size)
{
}

void Garment::SetSize(int newSize)
{
	size = newSize;
}

double Garment::GetTotalPrice()
{
	double totalPrice = this->price;

	if (size == Size_Small) 
	{
		totalPrice += 10;
	}
	else if (size == Size_Medium) 
	{
		totalPrice += 20;
	}
	else 
	{
		totalPrice += 30;
	}

	if (age < 10)
	{
		totalPrice += 5;
	}

	else if (age >=10 && age < 18)
	{
		totalPrice += 10;
	}

	else
	{
		totalPrice += 15;
	}

	if (isLocalManufacturer == false)
	{
		totalPrice += 10;
	}

	return totalPrice;
}