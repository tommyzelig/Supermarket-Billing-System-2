#pragma once
#include "pch.h"
#include "Product.h"

class NonFood : public Product
{

public:

	DECLARE_SERIAL(NonFood);

	NonFood()
	{

	}

	void Serialize(CArchive &ar)
	{
		Product::Serialize(ar);

		if (ar.IsStoring())  // SAVE
		{
			ar << isLocalManufacturer;

		}else  // Load
		{
			ar >> isLocalManufacturer;
		}
	}

	NonFood(const char * name , double price,bool isLocalManufacturer);


	bool GetIsLocalManufacturer() const { return isLocalManufacturer; }

protected:

	bool isLocalManufacturer;

};
