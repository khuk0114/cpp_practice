#include <iostream>
#include <vector>
#include <string>

#ifndef _PRINTER_H
#define _PRINTER_H

using namespace std;

class Printer {
protected:
	string model; //모델명
	string manufac; //제조사
	int printedCount; //인쇄 매수
	int availableCount; //용지 잔량
public:
	Printer(string model, string manufac, int pCnt, int aCnt) : model(model), manufac(manufac), printedCount(pCnt), availableCount(aCnt) {};
	void print(int pages);
	//void info();
};
void Printer::print(int pages) {
	if (availableCount >= pages) {
		availableCount -= pages;
		printedCount += pages;
		cout << "프린트하였습니다." << endl;
	}
	else {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
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
		cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
	}
}

void Ink::info() {
	cout << model << ", " << manufac << ", 남은 종이" << availableCount << " 장, " << "남은 잉크" << availableInk << endl;
}

class Laser : public Printer {
	int availableToner;
public:
	Laser() :Printer("SCX-6x45", "삼성전자", 3, 5), availableToner(20) {};
	void printLaser(int pages);
	void info();
};

void Laser::printLaser(int pages) {
	if (availableToner >= pages) {
		print(pages);
		availableToner -= pages;
	}
	else {
		cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
	}
}
void Laser::info() {
	cout << model << ", " << manufac << ", 남은 종이" << availableCount << " 장, " << "남은 토너" << availableToner << endl;
}

#endif