#pragma once
#include "Product.h"

class Food : public Product
{
	DECLARE_SERIAL(Food);

public:

	void Serialize(CArchive &ar)
	{
		Product::Serialize(ar);
		if (ar.IsStoring())
		{
			ar << isHot;
			ar << isDairy;
		}
		else
		{			
			ar >> isHot;
			ar >> isDairy;
		}
	}

	Food();
	Food(const char * name, double price, bool isHot, bool isDairy);
	double GetTotalPrice();

	void SetIsHot(bool newMode);

	bool GetIsDairy() const { return isDairy; }
	bool GetIsHot() const { return isHot; }

private:
	bool isHot;
	bool isDairy;
};