#include "pch.h"
#include "NonFood.h"

IMPLEMENT_SERIAL(NonFood, Product, 1);


NonFood::NonFood(const char * name, double price, bool isLocalManufacturer)
	: Product(name, price), isLocalManufacturer(isLocalManufacturer)
{

}
