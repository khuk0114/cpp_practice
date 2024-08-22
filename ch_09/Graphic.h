#include <iostream>

using namespace std;
#ifndef _GRAPHIC_H
#define _GRAPHIC_H
/*�޴� ȭ�鸸 �����*/
class GraphicEditor {
	Graphic 
public:
	GraphicEditor() { cout << "�׷��� �������Դϴ�." << endl; }

};

/*Shape*/
class Shape {
	Shape* next; //�ڱ����� ������
protected:
	virtual void draw() = 0; //���� �����Լ�
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