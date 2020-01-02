//Kushnir Roman K-11 Variant 74
#pragma once
#include <string>
class Lexer {
public:
	void load(std::string field_);  //Отримує рядок, який треба розділяти на поля
	bool next(std::string &field);  //Виділяє поля рядка з вилученням білих символів на початку та вкінці
	bool eof() const noexcept;      //Повертає true, якщо рядок розібрано до кінця
	void drop();
private:
	std::string field;              //Змінна в якій зберігається рядок
	bool eof_ = false;
	size_t pos = 0;
	const std::string delimeters = "#?"; //Містить роздільники у форматі string
};