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
	

int Bankomat::withdrawMoney()//Снять деньги
{
	int ClientSum;
	cout <<endl<< "Input sum to withdraw money: ";
	cin >> ClientSum;
	if (ClientSum > maxSumInDay) {
		cout << "Your sum>Max Sum in a day!" << endl;
		return 0;
	}
	else if (ClientSum < minSumInDay) {
		cout << "Your sum<Min sum to withdraw!" << endl;
		return 0;
	}
	else if (ClientSum %100!=0) {
		cout << "Your sum wrong to withdraw!" << endl;
		return 0;
	}
	else if (ClientSum > currentSum)
	{
		cout << "Your sum > current sum in bankomat ,sorry!" << endl;
		return 0;
	}
	else
	{
		if (!doWithdraw(ClientSum)) {
			cout << "Can't withdraw such sum." << endl;
		}
		return currentSum;
	}
}

bool Bankomat::doWithdraw(int ClientSum) {
	int sum = ClientSum;
	Nominal changed[NN];
	for (int i = 0; i < NN; i++) {
		changed[i] = Nominal(nominalsArray[i].value, nominalsArray[i].count);//Копируем массив номиналов чтоб не менять оригинал
	}

	for (int i = 0; i < NN; i++) {//Идем по массиву номиналов 4 раза
		//		cout << endl << "i=" << i << ", " << "sum=" << sum;
		Nominal* n = &changed[i];//Присваиваем копию в новый созданный массив номиналов чтоб не писать сто раз changed[i]
		if (n->value <= sum && n->count > 0) {//Если значение нашего текущего номинала который =копии оригинала,<= суммы клиента
			//и количество купюр нашего текущего номинала который =копии оригинала ,>0. То есть проверка можем ли мы выдать часть суммы из текущего номинала
			int ncount = sum / n->value;//Количество нужныъ купюр мы можем дать 7600/1000=7
			if (ncount > n->count) {//Если 7 больше чем количество что у нас есть 
				ncount = n->count;//Значит берем сколько есть 
			}
			n->count = n->count - ncount;//Отнимаем купюры=отдаем пользователю
//			cout << endl << "n.count=" << n->count;
			sum = sum - n->value * ncount;//Пересчитываем сумму после отнимания купюр
		}
	}

	if (sum == 0) {//Если все гуд и вся сумма выдалась наборами купюр что есть у нас
		for (int i = 0; i < NN; i++) {
			nominalsArray[i] = changed[i];//В оригинал записываем наш временный массив
//			cout << endl << "***Value=" << nominalsArray[i].value << " , " << "Count=" << nominalsArray[i].count;
		}
		currentSum = currentSum - ClientSum;//Отнимаем из текующей суммы клиентскую ибо получилось
		return true;
	}
	//Ничего не выдаем ибо не получилось,фиг тебе а не деньги
	return false;
}

void Bankomat::Print()
{
	cout << "Nominals:";
	for (int i = 0; i < NN; i++) {
		cout << endl << "Value=" << nominalsArray[i].value << " , " << "Count=" << nominalsArray[i].count;
	}
	cout << endl << "current sum = " << currentSum;
}
