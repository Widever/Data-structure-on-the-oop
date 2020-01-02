//Kushnir Roman K-11 Variant 74
#include <iostream>
#include "Lexer.h"
#include <string>
using namespace std;
bool Lexer::next(std::string &field_) {
	auto a = field.find_first_of(delimeters, pos);
	if (eof_)return false;
	//Якщо роздільники не знайдено
	if (a == string::npos) {
		field_ = field.substr(pos, field.length() - pos);
		auto b = field_.find_first_not_of("\t \v\r\f\n");
		if (b != string::npos)
		if (field[b] == '\n') 
		if (field_.length() != 0) {
			if (b == string::npos) {
				field_ = "";
			}

			else {
				field_ = field_.substr(b, field.length() - b);
				b = field_.find_last_not_of("\t \v\r\f\n");
				if (b != string::npos)
				if (field[b] == '\n') 
				field_ = field_.substr(0, b + 1);
			}
		}
		eof_ = true;
		return true;
	}
	//Якщо роздільники знайдено
	else {
		field_ = field.substr(pos, a - pos);
		pos = a + 1;
		auto b = field_.find_first_not_of("\t \v\r\f\n");
		if (b != string::npos)
		if (field[b] == '\n') 
		if (b == string::npos) {
			field_ = "";
		}

		else {
			field_ = field_.substr(b, field_.length() - b);
			b = field_.find_last_not_of("\t \v\r\f\n");
			if (b != string::npos)
			if (field[b] == '\n') 
			field_ = field_.substr(0, b + 1);
		}
		eof_ = false;
		return true;
	}
	

}
void Lexer::drop() {
	pos = 0;
	eof_ = false;
}

bool Lexer::eof() const noexcept {
	return eof_;
}
void Lexer::load(string field__) {
	field = field__;
}