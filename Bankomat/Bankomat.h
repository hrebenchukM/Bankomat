#pragma once
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;


class Bankomat
{
private:
	string IdentificationNumber;
	int currentSum;
	int maxSumInDay;
	int minSumInDay;
	static const int NN = 4;
	Nominal nominalsArray[NN];

public:
	Bankomat() = default;

	void Init(string id,int max,int min);
	string toString();
	void loadMoney(Nominal nominalsArray[]);
	int  withdrawMoney();



};

class Nominal
{
public:
	int value;
	int count;
	Nominal() = default;
	Nominal(int val, int n);
};





