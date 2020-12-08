#pragma once
#include "NonFood.h"

#define Size_Small 0
#define Size_Medium 1
#define Size_Large 2

class Garment : public NonFood // Garment , Clothes
{
	DECLARE_SERIAL(Garment);

public:

	Garment()
	{

	}

	void Serialize(CArchive &ar)
	{
		NonFood::Serialize(ar);

		if (ar.IsStoring())
		{
			ar << age;
			ar << size;

		}
		else
		{
			ar >> age;
			ar >> size;
		}
	}

	Garment(const char * name, double price, bool isLocalManufacturer, int age, int size);



	void SetSize(int newSize);

	virtual double GetTotalPrice();

	int GetAge() const { return age; }
	int GetSize() const { return size; }

private:
	int age;
	int size;
};