//Kushnir Roman K-11 Variant 74
#pragma 
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <list>


class Subject
{
public:
	Subject(std::string);
	class Details
	{
	public:
		
		Details(
			int mark,
		int testPoints,
		std::string numberGradebook,
		std::string surname,
		int semesterPoints,
		int sumMark,
		std::string name,

		std::string group
		);

		//Геттери
		int getmark();
		int gettestPoints();
		std::string getnumberGradebook();
		int getsemesterPoints();
		int getsumMark();
		std::string getname();
		std::string getsurname();
		
		std::string getgroup();
		//***

		//Оператори
		bool operator==(const Details& other) const noexcept;
		bool operator!=(const Details& other) const noexcept;
		bool operator<(const Details& other) const noexcept;
		bool operator<=(const Details& other) const noexcept;
		bool operator>(const Details& other) const noexcept;
		bool operator>=(const Details& other) const noexcept;
		//***
		
		void printstat();                //Виводить ынформацыю про студента у консоль
		void printstat(std::ofstream&);  //                                 у файл
		bool cheker();//Перевіряє дані на обмеження зазначені у варіанті

	private:
		int mark;				         //Оцінка за державною шкалою
		int testPoints;			         //Набрані на екзамені бали
		std::string numberGradebook;	 //Номер залікової книжки
		std::string surname;		     //Прізвище
		int semesterPoints;		         //Набрані впродовж семестру бали
		int sumMark;			         //сумарна оцінка за 100-бальною шкалою
		std::string name;	             //Ім'я
		std::string group;		         //Код групи
		std::string mark2();             //Оцінка за державною шкалою прописом
	
		int maxmark = 5, minmark = (-1);                          // Максимальна оцінка за державною шкалою / Мінімальна оцінка за державною шкалою
		int maxtestPoints = 40, mintestPoints = 0;                // Максимальний набраний на екзамені бал / Мінімальний набраний на екзамені бал 
		int maxsemesterPoints = 60, minsemesterPoints = 0;        // Максимальний бал за семестер / Мінімальний бал за семестер
		int minnotnulltestPoints = 24;                            // Мінімальний бал за екзамен, який не анулюється
		size_t maxsurname = 28, maxname = 26, maxgroup = 5;       // Максимальна довжина прізвища / ім'я / коду групи 
		int numberGradebooklenth = 7;                             // Кількість символів в номері залікової книжки
		int minfor3 = 60, minfor4 = 75, minfor5 = 90;             // Мінімальний сумарний бал для 3 / 4 / 5 
	
	};


	bool checkUnique(std::string);                               // Перевіряє на унікальність номер залікової книжки

	void print(int, std::ofstream&);                             // Виводять інформацію про предмет у файл
	void print(int);                                             //                                 у консоль
	
	void load(int,int,std::string,std::string,int,int,std::string,std::string); //Конструює і додає деталь у контейнер
	
	void averagePoint();                                         // Обчислює середній бал по предмету
	void students5();                                            // Обчислює кількість студентів, що здали предмет на 5
	bool cheker();                                               // Перевіряє дані на обмеження варіанту
	Details geti(int);                                           // Повертає і-ту деталь в контейнері
	size_t sizel();                                              // Повертає к-ть елементів у контейнері   

	std::string getsubjectName();                                
	int getstud5();
	double getaver();
	
	void printstat();                                            // Виводять інформацію по предмету у консоль
	void printstat(std::ofstream&);                              //                                 у файл

	void setsubjectName(std::string);

	//Оператори
	bool operator==(const Subject& other) const noexcept;
	bool operator!=(const Subject& other) const noexcept;
	bool operator<(const Subject& other) const noexcept;
	bool operator<=(const Subject& other) const noexcept;
	bool operator>(const Subject& other) const noexcept;
	bool operator>=(const Subject& other) const noexcept;
	//***

	


private:
	double aver;
	int stud5;
	std::string subjectName;
	double round(double&); //Округлює число до одного знаку після коми
	size_t maxsubjectName = 60;
	std::list<Details> l; //Контейнер деталей
};