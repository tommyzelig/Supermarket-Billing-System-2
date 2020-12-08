#include "pch.h"
#include"Product.h"
#include "string.h"

IMPLEMENT_SERIAL(Product, CObject, 1);



Product::Product()
{

}

Product::Product(const char *name, double price)
{
	this->price = price;

	int length = strlen(name);
	this->name = new char[length + 1];
	for (int i = 0;i < length; i++)
	{
		this->name[i] = name[i];
	}

	this->name[length] = '\0';

}

Product::~Product()
{
	if (name != NULL)
		delete name;
}
