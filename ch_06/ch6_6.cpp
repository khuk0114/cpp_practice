#include <iostream>

using namespace std;

class ArrayUtility2 {
public:
	//static int retSize;
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

//int ArrayUtility2::retSize = 10;

// s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	if (size == 0) return nullptr;

	int* Pcon = new int[size];

	for (int i = 0; i < size / 2; i++) {
		Pcon[i] = s1[i];
	}
	for (int i = 0; i < size / 2; i++) {
		Pcon[i + size / 2] = s2[i];
	}
	return Pcon;
	}

// s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����.
// �����ϴ� �迭�� ũ��� retSize�� ����. retSize�� 0�� ���, NULL ����

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	if (size == 0) {
		retSize = 0;
		return nullptr;
	}
	int* Prem = new int[size];
	int length = size / 2;
	bool* checkArr = new bool[length]; //�˻�� array
	//checkArr = { false, };

	for (int i = 0; i < length; i++) {
		checkArr[i] = true;
		for (int j = 0; j < length; j++) {
			if (s2[j] == s1[i]) { //s2���� s1[i]�� ���� �� �ִٸ�
				checkArr[i] = false; //i��° checkArr�� �����Ѵ�.
				break;
			}
		}

	}
	int cnt = 0;
	for (int i = 0; i < length; i++) {
		if (checkArr[i]) {	//arr���� ��Ƴ��� �͸�
			Prem[cnt] = s1[i];	//Prem�� �־��ش�.
			cnt++;
		}
	}
	retSize = cnt; //retSize�� Prem size �־��ֱ�

	if (retSize == 0) { //retSize�� 0�̸� NULL ����
		delete[] Prem;
		return nullptr;
	}
	
	delete[] checkArr;

	return Prem;
}


int main() {
	//ArrayUtility2 a;
	int x[5], y[5];
	cout << "���� 5���� �Է��϶�. �迭 x�� �����Ѵ�.>>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	
	cout << "���� 5���� �Է��϶�. �迭 y�� �����Ѵ�.>>";
	for (int i = 0; i < 5; i++) cin >> y[i];
	
	int* pConArr = ArrayUtility2::concat(x, y, 10); //pArr ����

	cout << "��ģ ���� �迭�� ����Ѵ�." << endl;
	//cout << ArrayUtility2::concat(x, y, 10);
	for (int i = 0; i < 10; i++) {
		cout << pConArr[i] << " ";
	}

	int retSize;
	int* pRemArr = ArrayUtility2::remove(x, y, 10, retSize);
	if (pRemArr != nullptr) {
		cout << "\n�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << endl;
		for (int i = 0; i < retSize; i++) {
			cout << pRemArr[i] << " ";
		}
	}
	else cout << "x[]���� y[]�� �� ��� �ƹ��͵� ���� �ʾҽ��ϴ�." << endl;
	
	
	//cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ 2\n";
	//cout << ArrayUtility2::remove(x, y, 10, );

	delete[] pConArr;
	delete[] pRemArr;

	return 0;
}