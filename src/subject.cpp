//Kushnir Roman K-11 Variant 74
#include "subject.h"
#include <string>
#include <iostream>
#include <cmath>
#include <list>
using namespace std;


void Subject::load(int arg1, int arg2, std::string arg3, std::string arg4, int arg5, int arg6, std::string arg7, std::string arg8) 
{
	Subject::Details A(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	if (!checkUnique(arg3) || !A.cheker()) throw invalid_argument("Data violates the variant limit");
	l.push_back(A);
}

Subject::Subject(string name) {
	subjectName = name;
}


bool Subject::cheker() {
	
	return (subjectName.length() >= 0 && subjectName.length() <= maxsubjectName);
}

bool Subject::Details::cheker() {
	bool res = true;
	if (mark < minmark || mark>maxmark || mark == 1) { res = false; cout<<"1";};
	if (testPoints < mintestPoints || testPoints>maxtestPoints) { res = false;cout<<"2"; };
	if (testPoints <= minnotnulltestPoints)testPoints = 0;
	if (semesterPoints < minsemesterPoints || semesterPoints>maxsemesterPoints) { res = false; cout<<"3";};
	if (testPoints + semesterPoints != sumMark) { res = false;cout<<"4"; };
	if (surname.length() > maxsurname) { res = false;cout<<"5"; };
	if (name.length() > maxname) { res = false; cout<<"6";};
	if (group.length() > maxgroup) { res = false; cout<<"7";};
	//for (int i = 0; i < group.length(); ++i){ if (!isalpha(group[i]) || !isdigit(group[i]) || group[i] != '-') { res = false; cout<<"8"<<group[i];}};
	for (int i = 0; i < numberGradebook.length(); ++i)if (!isdigit(numberGradebook[i])) { res = false; cout<<"9";};
	if (numberGradebook.length() != numberGradebooklenth) { res = false;cout<<"10"; };
	if (testPoints == 0 && (mark != (-1) && mark != 0 && mark != 2)) { res = false;cout<<"11"; };
	if (testPoints < minnotnulltestPoints && testPoints >= 0 && mark != 2) { res = false;cout<<"12"; };
	if (sumMark < 60 &&( mark != (-1) && mark != 0 && mark != 2)) { res = false; cout<<"13";};
	if (sumMark >= minfor3 && sumMark < minfor4 && mark != 3) { res = false; cout<<"14";};
	if (sumMark >= minfor4 && sumMark < minfor5 && mark != 4) { res = false; cout<<"15";};
	if (sumMark >= minfor5 && mark != 5) { res = false; cout<<"16";};
	//cout<<group;
	return res;
}

string Subject::getsubjectName() {
	return subjectName;
}

void Subject::setsubjectName(std::string s)
{
	subjectName = s;
}



bool Subject::operator==(const Subject & other) const noexcept
{
	return (this->subjectName == other.subjectName);
}

bool Subject::operator!=(const Subject & other) const noexcept
{
	return (this->subjectName != other.subjectName);
}

bool Subject::operator<(const Subject & other)const noexcept
{
	if (this->aver == other.aver) {
		if(this->stud5 == other.stud5) return (this->subjectName < other.subjectName);
		else return (this->stud5 < other.stud5);
	}
	else return (this->aver < other.aver);
}

bool Subject::operator<=(const Subject & other) const noexcept
{
	return (this->subjectName <= other.subjectName);
}

bool Subject::operator>(const Subject & other) const noexcept
{
	return (this->subjectName > other.subjectName);
}

bool Subject::operator>=(const Subject & other) const noexcept
{
	return (this->subjectName >= other.subjectName);
}

//Конструктор
Subject::Details::Details(
	int mark_,
	int testPoints_,
	string numberGradebook_,
	string surname_,
	int semesterPoints_,
	int sumMark_,
	string name_,

	string group_
)
{
	
	mark = mark_;
	testPoints = testPoints_;
	numberGradebook = numberGradebook_;
	semesterPoints = semesterPoints_;
	sumMark = sumMark_;
	name = name_;
	surname = surname_;
	
	group = group_;
}
//***

int Subject::Details::getmark() {
	return mark;
}

string Subject::Details::getnumberGradebook() {
	return numberGradebook;
}

int Subject::Details::getsemesterPoints() {
	return semesterPoints;
}

int Subject::Details::getsumMark() {
	return sumMark;
}

bool Subject::Details::operator==(const Details & other) const noexcept
{
	return !(*this != other);
}

bool Subject::Details::operator!=(const Details & other) const noexcept
{
	return this->numberGradebook != other.numberGradebook;
}

bool Subject::Details::operator<(const Details& other) const noexcept {
	return (this->numberGradebook < other.numberGradebook);
}

bool Subject::Details::operator<=(const Details& other) const noexcept {
	return (this->numberGradebook <= other.numberGradebook);
}

bool Subject::Details::operator>(const Details& other) const noexcept {
	return (this->numberGradebook > other.numberGradebook);
}

bool Subject::Details::operator>=(const Details& other) const noexcept {
	return (this->numberGradebook >= other.numberGradebook);
}

int Subject::Details::gettestPoints() {
	return testPoints;
}

string Subject::Details::getname()
{
	return name;
}

string Subject::Details::getsurname()
{
	return surname;
}


string Subject::Details::getgroup()
{
	return group;
}

Subject::Details Subject::geti(int i) {
	auto iterator = l.begin();
	
	for (int j = 0; j < i; j++)
		iterator++;
	return *iterator;
}

size_t Subject::sizel() {
	return l.size();
}

void Subject::print(int j) {
		cout << j+1 << "#" << geti(j).getmark() << "#" << geti(j).gettestPoints() << "#" << geti(j).getnumberGradebook()
			<< "#" << geti(j).getsurname() << "#" << geti(j).getsemesterPoints() << "#" << geti(j).getsumMark() << "#" << geti(j).getname() << "#"
			<< subjectName << "#" << geti(j).getgroup() << endl;
}

void Subject::print(int j,ofstream& out) {
	out << j+1 << "#" << geti(j).getmark() << "#" << geti(j).gettestPoints() << "#" << geti(j).getnumberGradebook()
		<< "#" << geti(j).getsurname() << "#" << geti(j).getsemesterPoints() << "#" << geti(j).getsumMark() << "#" << geti(j).getname() << "#"
		<< subjectName << "#" << geti(j).getgroup() << endl;
}

void Subject::averagePoint() {
	auto begin = l.begin();
	double aver_;
	double sum = 0;
	auto end = l.end();
	for (; begin != end; begin++)
		sum += (*begin).getsumMark();
	aver_ = sum / l.size();
	aver = round(aver_);
}

double Subject::round(double& a) {
	double afirst = a;
	double a11 = a*100; 
	int b1 = a11;
	int b = a*10;
	b *= 10;
	int r = b1 - b;
	for (int i = 2; r == 4&&i<8; i++) {
		a11 =a*pow(10,i+1);
		b1 = a11;
		b = a * pow(10,i);
		b *= 10;
		r = b1 - b;
	}
	if (r > 4) {
		a *= 10;
		b = a+1;
		a = b;
		a /= 10;
	}
	if (r < 4||r==4) {
		a *= 10;
		b = a;
		a = b;
		a /= 10;
	}
	return a;
}

void Subject::students5() {
	auto begin = l.begin();
	double counter=0;
	double sum = 0;
	auto end = l.end();
	for (; begin != end; begin++)
		if ((*begin).getmark() == 5)counter++;
	stud5 = counter;
}

double Subject::getaver() {
	return aver;
}

int Subject::getstud5() {
	return stud5;
}

void Subject::Details::printstat(ofstream& outf) {
	outf << "\t" << surname << "#" << name << "#" << numberGradebook << "#" << group << "#" << mark2() << endl;
}

void Subject::Details::printstat() {
	cout << "\t" << surname << "#" << name << "#" << numberGradebook << "#" << group << "#" << mark2() << endl;
}

string Subject::Details::mark2() {
	if (mark == (-1)) return "not allow to take";
	if (mark == 0) return "absent";
	if (mark == 2) return "poor";
	if (mark == 3) return "satisfactory";
	if (mark == 4) return "good";
	if (mark == 5) return "excellent";
	else return "";
}

void Subject::printstat(ofstream& outf) {
	outf << subjectName << "#" << aver << "#" << stud5 << endl;
	l.sort();
	auto begin = l.begin();
	auto end = l.end();
	for (; begin != end; ++begin) {
		if ((*begin).getsumMark() < 60) (*begin).printstat(outf);
	}
}

void Subject::printstat() {
	cout << subjectName << "#" << aver << "#" << stud5 << endl;
	l.sort();
	auto begin = l.begin();
	auto end = l.end();
	for (; begin != end; ++begin) {
		if ((*begin).getsumMark() < 60) (*begin).printstat();
	}
}


bool Subject::checkUnique(string numberGradebook_) {
	bool res=true;
	auto begin = l.begin();
	auto end = l.end();
	for (; begin != end; begin++) {
		if (numberGradebook_ == (*begin).getnumberGradebook()) res = false;
	}
	return res;
}