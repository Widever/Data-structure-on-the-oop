//Kushnir Roman K-11 Variant 74
#include "builder.h"
#include "Lexer.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Builder::loadData(Info& info, const char* filename)
{
	ifstream i(filename);
	int numberofline = 0, line = 0, footer = 0, lineh, linef, liner;
	string input, field;
	bool less = false, equal = false;
	Lexer lex;
	size_t header=0;
	bool header_OK = false;
	int headers = 0, footers = 0;
	
	while (!i.eof()) {

		getline(i, input);
		line++;
		lex.load(input);
		int amh = counterheaders(input);
		headers += amh;
		size_t lh = lenth_header(input);
		int amf = counterfooters(input);
		footers += amf;
		size_t lf = lenth_footer(input);
		lex.drop();
		if(headers>1) throw out_of_range("101 -1 There is more than one header");
		if(footers>1) throw out_of_range("201 -1 There is more than one footer");
		if(amh!=0)
		{
			if (lh == 2 && amh == 1) {
				while (field != "header")lex.next(field);
				lex.next(field);
				try {
					header = stoi(field);
				}
				catch (const invalid_argument &) {
					throw invalid_argument("104 -1 Can not convert");
				}
				if (header > 0) header_OK = true;
				info.setheader(header);
				lineh = line;
			}
			else {
				if (amh == 0)throw out_of_range("100 -1 Absent header");
				if (amh > 1) { throw out_of_range("101 -1 There is more than one header");}
				if (amh == 1)throw out_of_range("103 -1 Inappropriate number of fields in the header");
			}
		}
		if(amf!=0)
		{
			if (lf == 2 && amf == 1) {
				while (field != "footer")lex.next(field);
				lex.next(field);
				try {
					footer = stoi(field);
				}
				catch (const invalid_argument &) {
					throw invalid_argument("204 -1 Can not convert");
				}
				info.setfooter(footer);
				linef = line;
			}
			else {
				if (amh == 0)throw out_of_range("200 -1 Absent footer");
				if (amh > 1) { throw out_of_range("201 -1 There is more than one footer");}
				if (amf == 1)throw out_of_range("203 -1 Inappropriate number of fields in the footer");
			}
		}
		if (amh==0 && counterfields(input) == 10 && amf == 0) {
			numberofline++;
			liner = line;
			lex.next(field);
			while (field == "")lex.next(field);
			try {
				stoi(field);
			}
			catch (const invalid_argument &) {
				string mess = "303 ";
				mess += to_string(line);
				mess += " Can not convert";
				throw invalid_argument(mess);
			}
			if (stoi(field) != numberofline) { 
				string mess = "301 ";
				mess += to_string(line);
				mess += " Incorrect numbering of records";
				throw out_of_range(mess);
			}

			lex.next(field);
			int mark_;
			try {
				mark_ = stoi(field);
			}
			catch (const invalid_argument &) {
				string mess = "303 ";
				mess += to_string(line);
				mess += " Can not convert";
				throw invalid_argument(mess);
			}
			
			mark_ = stoi(field);
			lex.next(field);
			int testPoints_;
				try {
					testPoints_ = stoi(field);
				}
				catch (const invalid_argument &) {
					string mess = "303 ";
					mess += to_string(line);
					mess += " Can not convert";
					throw invalid_argument(mess);
				}
				testPoints_ = stoi(field);

			lex.next(field);
			string numberGradebook_;
			if (field == "")
			{
				string mess = "303 ";
				mess += to_string(line);
				mess += " Empty field";
				throw invalid_argument(mess);
			}
			numberGradebook_ = field;
			lex.next(field);
			string surname_;
			if (field == "")
			{
				string mess = "303 ";
				mess += to_string(line);
				mess += " Empty field";
				throw invalid_argument(mess);
			}
			surname_ = field;
			lex.next(field);
			int semesterPoints_;
			try {
				semesterPoints_ = stoi(field);
			}
			catch (const invalid_argument&) {
				string mess = "303 ";
				mess += to_string(line);
				mess += " Can not convert";
				throw invalid_argument(mess);
			}
			semesterPoints_ = stoi(field);
			lex.next(field);
			int sumMark_;
			try {
				sumMark_ = stoi(field);
			}
			catch (const invalid_argument&) {
				string mess = "303 ";
				mess += to_string(line);
				mess += " Can not convert";
				throw invalid_argument(mess);
			}
			sumMark_ = stoi(field);
			lex.next(field);
			string name_;
			if (field == "")
			{
				string mess = "303 ";
				mess += to_string(line);
				mess += " Empty field";
				throw invalid_argument(mess);
			}
			name_ = field;
			lex.next(field);
			string subjectName_;
			if (field == "")
			{
				string mess = "303 ";
				mess += to_string(line);
				mess += " Empty field";
				throw invalid_argument(mess);
			}
			subjectName_ = field;
			if (header_OK) {
				if (subjectName_.size() < header)less = true;
				if (subjectName_.size() == header)equal = true;
			}
			lex.next(field);
			string group_;
			if (field == "")
			{
				string mess = "303 ";
				mess += to_string(line);
				mess += " Empty field";
				throw invalid_argument(mess);
			}
			group_ = field;

			info.load(subjectName_, mark_, testPoints_, numberGradebook_, surname_, semesterPoints_, sumMark_, name_, group_);
		}
		else {
			
			if (counterfields(input) != 1&&amh==0&&amf==0) {
				string mess = "302 ";
				mess += to_string(line);
				mess += " Inappropriate number of fields per line";
				throw out_of_range(mess);
			}
		}
	}
	//if (!(!less && equal))throw out_of_range("102 -1 the header does not match the contents of the file");
	if (less||!equal)throw out_of_range("102 -1 the header does not match the contents of the file");
	if (footer != numberofline)throw out_of_range("202 -1 The footer does not match the contents of the file");
	if (!(lineh < liner&&liner < linef))throw out_of_range("300 -1 Broken order");


} 

int Builder::lenth_header(string input) {
	string a;
	Lexer lex;
	lex.load(input);
	bool b = false;
	int lenth = 0;
	while (!lex.eof())
	{
		lex.next(a);
		if (a == "header") b = true;
		if (b) lenth++;
	}
	return lenth;
}

int Builder::counterheaders(string input) {
	int amount = 0;
	string a;
	Lexer lex;
	lex.load(input);
	while (!lex.eof()) {
		lex.next(a);
		if (a == "header") ++amount;
	}
	return amount;
}

size_t Builder::lenth_footer(string input) {
	string a;
	bool b = false;
	int lenth = 0;
	Lexer lex;
	lex.load(input);
	while (!lex.eof())
	{
		lex.next(a);
		if (a == "footer") b = true;
		if (b) lenth++;
	}
	return lenth;
}

int Builder::counterfooters(string input) {
	int amount = 0;
	string a;
	Lexer lex;
	lex.load(input);
	while (!lex.eof()) {
		lex.next(a);
		if (a == "footer") ++amount;
	}
	return amount;
}

int Builder::counterfields(string input) {
	int amount = 0;
	string a;
	Lexer lex;
	lex.load(input);
	while (!lex.eof()) {
		lex.next(a);
		++amount;
	}
	
	return amount;
}