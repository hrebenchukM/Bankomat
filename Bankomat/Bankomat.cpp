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
	

int Bankomat::withdrawMoney()//����� ������
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
		changed[i] = Nominal(nominalsArray[i].value, nominalsArray[i].count);//�������� ������ ��������� ���� �� ������ ��������
	}

	for (int i = 0; i < NN; i++) {//���� �� ������� ��������� 4 ����
		//		cout << endl << "i=" << i << ", " << "sum=" << sum;
		Nominal* n = &changed[i];//����������� ����� � ����� ��������� ������ ��������� ���� �� ������ ��� ��� changed[i]
		if (n->value <= sum && n->count > 0) {//���� �������� ������ �������� �������� ������� =����� ���������,<= ����� �������
			//� ���������� ����� ������ �������� �������� ������� =����� ��������� ,>0. �� ���� �������� ����� �� �� ������ ����� ����� �� �������� ��������
			int ncount = sum / n->value;//���������� ������ ����� �� ����� ���� 7600/1000=7
			if (ncount > n->count) {//���� 7 ������ ��� ���������� ��� � ��� ���� 
				ncount = n->count;//������ ����� ������� ���� 
			}
			n->count = n->count - ncount;//�������� ������=������ ������������
//			cout << endl << "n.count=" << n->count;
			sum = sum - n->value * ncount;//������������� ����� ����� ��������� �����
		}
	}

	if (sum == 0) {//���� ��� ��� � ��� ����� �������� �������� ����� ��� ���� � ���
		for (int i = 0; i < NN; i++) {
			nominalsArray[i] = changed[i];//� �������� ���������� ��� ��������� ������
//			cout << endl << "***Value=" << nominalsArray[i].value << " , " << "Count=" << nominalsArray[i].count;
		}
		currentSum = currentSum - ClientSum;//�������� �� �������� ����� ���������� ��� ����������
		return true;
	}
	//������ �� ������ ��� �� ����������,��� ���� � �� ������
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
