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
	fill_n(p, 10, 0); //p�� ��� 0���� ä���
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
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { //11���� pop�ϸ�, ���������� stack empty�� �ȴ�.
		if (a.pop(n))cout << n << ' '; //pop �� �� ���
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;

	return 0;
}