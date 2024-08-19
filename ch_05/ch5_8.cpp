#include <iostream>

using namespace std;

class MyIntStack {
	int* p; //new
	int size;
	int tos;
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack::MyIntStack() {
	this->size = 10;
	this->p = new int[size];
	this->tos = 0;
}
MyIntStack::MyIntStack(int size) {
	this->size = size;
	this->p = new int[size];
	this->tos = 0;
}

MyIntStack::MyIntStack(const MyIntStack& s) { //복사생성자
	this->size = s.size;
	this->p = new int[s.size];
	this->tos = s.tos;
}

MyIntStack::~MyIntStack() {
	delete[] p;
}

bool MyIntStack::push(int n) {
	if (tos > this->size) return false;
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
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //복사 생성
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;

	return 0;
}