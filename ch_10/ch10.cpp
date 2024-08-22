#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Circle {
	string name; //이름
	int radius; //반지름
public:
	Circle(int radius, string name) : radius(radius), name(name) {}
	double getArea();
	string getName();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}
string Circle::getName() {
	return name;
}




int main() {
	vector<Circle*> v;
	cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;
	int num;
	while (1) {
		cin >> num;
		switch (num) {
		case 1:
			this->insert();
			break;
		case 2:
			this->del();
			break;
		case 3:
			this->all();
			break;
		case 4:
			return;
		default:
			cout << "제대로 입력해주세요";
		}
	}

	
}
