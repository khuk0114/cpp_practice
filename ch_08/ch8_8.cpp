#include "Printer.h"

int main() {
	Ink ink;
	Laser laser;
	char YN;
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����.\n";
	cout << "��ũ�� : ";
	ink.info();
	cout << "������ : ";
	laser.info();

	while(1) {
		int type, page;
		
		cout << "������(1: ��ũ��, 2: ������)�� �ż� �Է�>>";
		cin >> type >> page;
		if (type == 1)
			ink.printInk(page);
		else if (type == 2)
			laser.printLaser(page);
		else {
			cout << "����� �� �����͸� ������ �ֽʽÿ�" << endl;
			continue;
		}
		ink.info();
		laser.info();
		tryAgain:
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>>";
		cin >> YN;
		if (YN == 'Y' || YN == 'y') continue;
		else if (YN == 'n' || YN == 'N') break;
		else goto tryAgain;
	}

	
	return 0;
}