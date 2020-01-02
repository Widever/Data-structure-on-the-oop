//Kushnir Roman K-11 Variant 74
#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <list>
#include "subject.h"
class Info
{
public:
	void load(std::string, int, int, std::string, std::string, int, int, std::string, std::string);//Додає деталі у конкретну сутність
	void load(std::string);//Конструює і додає сутність в контейнер
	size_t size();         //Повертає к-ть елементів у контейнері
	void setheader(int);   
	void setfooter(int);
	bool output(std::string); //Обробляє команду -output
	bool stat(std::string);   //Обробляє команду -stat
private:
	int header, footer;
	double averange();
	Subject geti(int i);
	std::list<Subject> s; //Контейнер сутностей
};