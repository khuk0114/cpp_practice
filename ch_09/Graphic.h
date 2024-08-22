#include <iostream>

using namespace std;
#ifndef _GRAPHIC_H
#define _GRAPHIC_H
/*메뉴 화면만 띄워줌*/
class GraphicEditor {
	Graphic 
public:
	GraphicEditor() { cout << "그래픽 에디터입니다." << endl; }

};

/*Shape*/
class Shape {
	Shape* next; //자기참조 포인터
protected:
	virtual void draw() = 0; //순수 가상함수
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
};

void Shape::paint() {
	draw();
}
Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}

/*Circle*/
class Circle : public Shape {
protected:
	virtual void draw();
};

void Circle::draw() {
	cout << "Circle" << endl;
}

/*Rect*/
class Rect : public Shape {
protected:
	virtual void draw();
};

void Rect::draw() {
	cout << "Rectangle" << endl;
}

/*Line*/
class Line : public Shape {
protected:
	virtual void draw();
};

void Line::draw() {
	cout << "Line" << endl;
}







#endif