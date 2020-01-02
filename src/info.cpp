//Kushnir Roman K-11 Variant 74
#include "info.h"
#include <string>
#include <iostream>

using namespace std;

void Info::load(std::string subjectName_, int arg1, int arg2, std::string arg3, std::string arg4, int arg5, int arg6, std::string arg7, std::string arg8) {
	auto begin = s.begin();
	auto end = s.end();
	bool find = false;
	for (; begin != end; ++begin) {
		auto &i = *begin;
		if (i.getsubjectName() == subjectName_) { i.load(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); find = true; }
	}
	if (!find) {
		load(subjectName_);
		begin = s.begin();
		end = s.end();
		for (; begin != end; ++begin) {
			auto &i = *begin; 
				if (i.getsubjectName() == subjectName_) { i.load(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8); }
		}
	}
	
}

void Info::load(string subjectName_) {
		Subject A(subjectName_);
		if (!A.cheker()) throw invalid_argument("Data violates the variant limit");
		s.push_back(A);
}

size_t Info::size() {
	return s.size();
}

Subject Info::geti(int i) {
	auto iterator = s.begin()++;
	for(int j=0;j<i;j++)
	iterator++;
	return *iterator;
}

bool Info::output(string fout) {
	bool res=true;
	
	if (fout == "#con") {
	cout<<"header#"<< header << endl;
		for (int i = 0; i <= s.size() - 1; i++) {
			for (int j = 0; j <= geti(i).sizel() - 1; j++)
				geti(i).print(j);
		}
		cout << "footer#" << footer << endl;
	}
	else {
		ofstream out(fout);
		if (out.is_open()) {
			out<<"header#"<< header << endl;
			for (int i = 0; i <= s.size() - 1; i++) {
				for (int j = 0; j <= geti(i).sizel() - 1; j++)
					geti(i).print(j, out);
			}
			out << "footer#" << footer << endl;
		}
		else res = false;
		if (out.fail())res = false;
		if (!res)cout << ": UPS" << endl;
		else cout << ": OK" << endl;
	}
	
	return res;
}


bool Info::stat(string fout) {
	bool res = true;
	auto begin = s.begin();
	auto end = s.end();
	for (; begin != end; begin++) {
		(*begin).averagePoint();
		(*begin).students5();
	}
	s.sort();
	begin = s.begin();
	double aver = averange();
	if (fout == "#con") {
		for (; begin != end; begin++)
			if ((*begin).getaver() > aver) (*begin).printstat();
	}
	else {
		ofstream out(fout);
		if (out.is_open()) {
			for (; begin != end; begin++)
				if ((*begin).getaver() > aver) (*begin).printstat(out);
		}
		else res = false;

		if (out.fail()) res = false;
		if (!res)cout << ": UPS" << endl;
		else cout << ": OK"<<endl;
	}
	return res;
}


double Info::averange() {
	auto begin = s.begin();
	double sum = 0;
	auto end = s.end();
	for (; begin != end; begin++) {
		(*begin).averagePoint();
		sum += (*begin).getaver();
	}
	return sum / s.size();
}

void Info::setheader(int header_) {
	header = header_;
}

void Info::setfooter(int footer_) {
	footer = footer_;
}