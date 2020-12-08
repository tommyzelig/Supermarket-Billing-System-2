#pragma once

class Product : public CObject
{

	DECLARE_SERIAL(Product);

public:

	void Serialize(CArchive &ar)
	{
		CObject::Serialize(ar);

		if (ar.IsStoring()) // Save
		{
			ar << price;
		}
		else// loading
		{
			ar >> price;
		}

	}

	Product();
	Product(const char *name, double price);

	// virtual double GetTotalPrice() = 0;

	virtual double GetTotalPrice()
	{
		return 0.0;
	}


	virtual ~Product();


	char* GetName() const { return name; }

	double GetPrice() const { return price; }


protected:
	char *name = NULL;
	double price;
};






