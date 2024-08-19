#include <iostream>

using namespace std;

class ArrayUtility2 {
public:
	//static int retSize;
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

//int ArrayUtility2::retSize = 10;

// s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
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

// s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴.
// 리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우, NULL 리턴

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	if (size == 0) {
		retSize = 0;
		return nullptr;
	}
	int* Prem = new int[size];
	int length = size / 2;
	bool* checkArr = new bool[length]; //검사용 array
	//checkArr = { false, };

	for (int i = 0; i < length; i++) {
		checkArr[i] = true;
		for (int j = 0; j < length; j++) {
			if (s2[j] == s1[i]) { //s2에서 s1[i]과 같은 게 있다면
				checkArr[i] = false; //i번째 checkArr가 삭제한다.
				break;
			}
		}

	}
	int cnt = 0;
	for (int i = 0; i < length; i++) {
		if (checkArr[i]) {	//arr에서 살아남은 것만
			Prem[cnt] = s1[i];	//Prem에 넣어준다.
			cnt++;
		}
	}
	retSize = cnt; //retSize에 Prem size 넣어주기

	if (retSize == 0) { //retSize가 0이면 NULL 리턴
		delete[] Prem;
		return nullptr;
	}
	
	delete[] checkArr;

	return Prem;
}


int main() {
	//ArrayUtility2 a;
	int x[5], y[5];
	cout << "정수 5개를 입력하라. 배열 x에 삽입한다.>>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	
	cout << "정수 5개를 입력하라. 배열 y에 삽입한다.>>";
	for (int i = 0; i < 5; i++) cin >> y[i];
	
	int* pConArr = ArrayUtility2::concat(x, y, 10); //pArr 생성

	cout << "합친 정수 배열을 출력한다." << endl;
	//cout << ArrayUtility2::concat(x, y, 10);
	for (int i = 0; i < 10; i++) {
		cout << pConArr[i] << " ";
	}

	int retSize;
	int* pRemArr = ArrayUtility2::remove(x, y, 10, retSize);
	if (pRemArr != nullptr) {
		cout << "\n배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
		for (int i = 0; i < retSize; i++) {
			cout << pRemArr[i] << " ";
		}
	}
	else cout << "x[]에서 y[]를 뺀 결과 아무것도 남지 않았습니다." << endl;
	
	
	//cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 2\n";
	//cout << ArrayUtility2::remove(x, y, 10, );

	delete[] pConArr;
	delete[] pRemArr;

	return 0;
}