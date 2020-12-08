#pragma once
#include "NonFood.h"

class CleanProduct : public NonFood
{

	DECLARE_SERIAL(CleanProduct);

public:

	CleanProduct()
	{

	}

	void Serialize(CArchive &ar)
	{
		NonFood::Serialize(ar);

		if (ar.IsStoring())
		{
			ar << isDangerus;

		}
		else
		{
			ar >> isDangerus;
		}
	}

	CleanProduct(const char * name, double price, bool isLocalManufacturer, bool isDangerus = false);

	virtual double GetTotalPrice();

	void SetDangerous(bool newMode);


	bool GetIsDangerous() const { return isDangerus; }

private:

	
	bool isDangerus = false;


};