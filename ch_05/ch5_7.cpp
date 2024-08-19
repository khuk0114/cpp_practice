#include <iostream>

using namespace std;

class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack::MyIntStack() {
	fill_n(p, 10, 0); //p에 모두 0으로 채우기
	tos = 0;
}
bool MyIntStack::push(int n) {
	if (tos > 9) return false;
	p[tos] = n;
	tos++;
	return true;
}

bool MyIntStack::pop(int& n) {
	if (tos <= 0) return false;
	tos--;
	n = p[tos];
	return true;
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { //11개를 pop하면, 마지막에는 stack empty가 된다.
		if (a.pop(n))cout << n << ' '; //pop 한 값 출력
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;

	return 0;
}