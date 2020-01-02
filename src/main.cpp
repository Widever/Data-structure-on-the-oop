//Kushnir Roman K-11 Variant 74
#include <iostream>
#include "builder.h"
#include "info.h"
#include "Lexer.h"
#include <exception>
#include <fstream>
#include "copyright.h"
using namespace std;
//Довідка
void help() {
	cout<<endl << "The program handles the command line: " << endl
 << "<executable file> <the name of the input file> {<command> <the name of the output file>}" << endl
		<< "<command> - one of -output, -stat" << endl
		 << "If #con is specified as the output file name, the output must go to the console." << endl
<< "Curly brackets mean that the corresponding part of the command line can be arbitrary number of times(in particular, none)." << endl;
	cout<<endl<<"Поля вхідного файлу попорядку:"<<endl<<"header(найменша довжина назви предмета"<<endl<<'\t'<<"оцінка за державною шкалою(2-5, 0 - не з'явився, -1 - недопущений)"<<endl<<'\t'<<"набрані на екзамені бали(не більше 40, якщо менше 24 = 0)"<<endl<<'\t'<<"номер залікової книжки(7 цифр, унікальний для студента)"<<endl<<'\t'<<"прізвище(не більше 28 символів)"<<endl<<'\t'<<"набрані впродовж семестру бали(не більше 60)"<<endl<<'\t'<<"сумарна оцінка по 100-бальній шкалі(сума екз+семестр)"<<endl<<'\t'<<"ім'я(не більше 26 символів)"<<endl<<'\t'<<"предмет(до 60 символів включно)"<<endl<<'\t'<<"код групи(не більше 5 літер, може містити цифри та дефіс)"<<endl;
	cout<<"Команда -stat: знаходить предмети,середній бал за які, вищий середнього за всю сесію,  виводить інформацію по кожному з них(на першому рядку назву/середній бал/к-ть студентів, що склали на 5. В наступних рядках студенти, що не склали предмет)"<<endl<<"Команда -output: виводить інформацію в файл"<<endl<<"footer(загальна к-ть записів)"<<endl;

}
//Перевіряє файл на txt
bool txt(string s) {
	if (s.size() <= 4)return false;
	else return s.substr(s.size() - 4) == ".txt";
}
//Обробляє вхідний файл
bool input(Info& info, const char* filename) {
	Builder B;
		if (!txt(filename)) {
			cout << "UPS" << endl;
			throw runtime_error("400 -1 Not txt file");
		}
		else {
			B.loadData(info, filename);
			cout << " OK\n";
		}
			
	return true;
}

//Обробляє команду
bool do_command(string command, Info& info, string fname) {
	bool res = true;
	if (command == "-stat") {
		if (fname == "#con") {
			cout << command.substr(1) << " " << fname<<":\n";
			info.stat(fname);
		}
		else {
			cout << command.substr(1) << " " << fname;
			info.stat(fname);
		}
	}
	if (command == "-output") {
		if (fname == "#con") {
			cout << command.substr(1) << " " << fname<<"\n";
			info.output(fname);
		}
		else {
			cout << command.substr(1) << " " << fname;
			info.output(fname);
		}
	}
	else if(command != "-stat")res = false;
	return res;
}

int main(int argc, char **argv) {
	Info info;
	string input_, a, b, help_;

	copyright();
	cout<<"press ENTER for continue or print help"<<endl;
	getline(cin,help_);
	if(help_=="help")help();
	cout << "*****" << endl;
	//const char* binp = "in.txt";
	try {
		if (argc != 1) {
			cout << "input " << argv[1] << ":";
			input(info, argv[1]);
		}
		else cout << "nothing to do" << endl;
		for (int i = 2; i <= argc - 1; i++) {
			a = argv[i];
				if (a == "-stat" || a == "-output") {
					if (i != argc - 1) {
						b = argv[i + 1];
						if (txt(b) || b == "#con") {
							do_command(argv[i], info, argv[i + 1]);
							i++;
						}
						else cout << a.substr(1) << " undefined" << endl;
					}
					else cout << a.substr(1) << " undefined" << endl;
				}
				else cout << a << ": ignored" << endl;
			
		}
		cout<<"*****" << endl;
		
	}
	catch (const runtime_error &ex)
	{
		cout << "UPS\n" << "*****" << endl;
			cout<<ex.what()<<endl;
	}
	catch (const out_of_range &ex)
	{
		cout << "UPS\n" << "*****" << endl;
			cout<<ex.what()<<endl;
	}
	catch (const invalid_argument &ex)
	{
		cout << "UPS\n" << "*****" << endl;
			cout<<ex.what()<<endl;
	}
	catch (const bad_alloc)
	{
		cout << "UPS\n" << "*****" << endl;
			cout<<"500 -1 bad_alloc"<<endl;
	}
}