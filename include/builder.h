//Kushnir Roman K-11 Variant 74
#pragma once
#include <iostream>
#include <exception>
#include "info.h"
#include <fstream>
#include <string>
class Builder
{
public:
	void loadData(Info&, const char* filename); //Завантажує дані з файла у об'єкт типу Info
private:
	int lenth_header(std::string);              //Повертає кількість полів в header
	int counterheaders(std::string);            //Повертає кількість header
	size_t lenth_footer(std::string input);     //Повертає кількість полів в footer
	int counterfooters(std::string);            //Повертає кількість footer
	int counterfields(std::string);             //Повертає кількість полів
};