#include <iostream>
#include <vector>
#include <string>

#ifndef _PRINTER_H
#define _PRINTER_H

using namespace std;

class Printer {
protected:
	string model; //�𵨸�
	string manufac; //������
	int printedCount; //�μ� �ż�
	int availableCount; //���� �ܷ�
public:
	Printer(string model, string manufac, int pCnt, int aCnt) : model(model), manufac(manufac), printedCount(pCnt), availableCount(aCnt) {};
	void print(int pages);
	//void info();
};
void Printer::print(int pages) {
	if (availableCount >= pages) {
		availableCount -= pages;
		printedCount += pages;
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
	else {
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
}




class Ink : public Printer {
	int availableInk;
public:
	Ink() : Printer("officejet V40", "HP", 5, 5), availableInk(10) {};
	void printInk(int pages);
	void info();
};

void Ink::printInk(int pages) {
	if (availableInk >= pages) {
		print(pages);
		availableInk -= pages;
	}
	else {
		cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
}

void Ink::info() {
	cout << model << ", " << manufac << ", ���� ����" << availableCount << " ��, " << "���� ��ũ" << availableInk << endl;
}

class Laser : public Printer {
	int availableToner;
public:
	Laser() :Printer("SCX-6x45", "�Ｚ����", 3, 5), availableToner(20) {};
	void printLaser(int pages);
	void info();
};

void Laser::printLaser(int pages) {
	if (availableToner >= pages) {
		print(pages);
		availableToner -= pages;
	}
	else {
		cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
}
void Laser::info() {
	cout << model << ", " << manufac << ", ���� ����" << availableCount << " ��, " << "���� ���" << availableToner << endl;
}

#endif