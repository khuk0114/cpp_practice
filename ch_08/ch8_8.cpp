#include "Printer.h"

int main() {
	Ink ink;
	Laser laser;
	char YN;
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다.\n";
	cout << "잉크젯 : ";
	ink.info();
	cout << "레이저 : ";
	laser.info();

	while(1) {
		int type, page;
		
		cout << "프린터(1: 잉크젯, 2: 레이저)와 매수 입력>>";
		cin >> type >> page;
		if (type == 1)
			ink.printInk(page);
		else if (type == 2)
			laser.printLaser(page);
		else {
			cout << "제대로 된 프린터를 선택해 주십시오" << endl;
			continue;
		}
		ink.info();
		laser.info();
		tryAgain:
		cout << "계속 프린트 하시겠습니까?(y/n)>>";
		cin >> YN;
		if (YN == 'Y' || YN == 'y') continue;
		else if (YN == 'n' || YN == 'N') break;
		else goto tryAgain;
	}

	
	return 0;
}