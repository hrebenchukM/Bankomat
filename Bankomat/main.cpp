#include "Bankomat.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;


int main()
{
	Nominal n1000(1000, 7);
	Nominal n500(500, 7);
	Nominal n200(200, 1);
	Nominal n100(100, 1);
	Nominal array[]{n1000,n500,n200,n100};
	Bankomat bank;
	bank.Init("id7777", 10000, 100);
	bank.loadMoney(array);
	cout <<endl<<"toString()="<< bank.toString() << endl;


	bank.Print();
	bank.withdrawMoney();
	bank.Print();
	
}