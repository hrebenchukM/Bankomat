#include "Bankomat.h"

Nominal::Nominal(int val, int n):value(val),count(n)
{}


void Bankomat::Init(string id, int max, int min)
{
	 IdentificationNumber=id;
	 maxSumInDay=max;
	 minSumInDay=min;
}

string Bankomat::toString()
{
	return to_string(currentSum);
}

void Bankomat::loadMoney(Nominal nominals[])
{
	 currentSum = 0;
	 for (int i = 0; i < NN; i++) {
		 nominalsArray[i] = nominals[i];
		 currentSum += nominalsArray[i].value * nominalsArray[i].count;
	 }
}

int Bankomat::withdrawMoney()
{
	return 0;
}
