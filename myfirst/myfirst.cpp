#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using namespace std;

bool space(char c)
{

	return isspace(c);

}

bool not_space(char c)
{

	return !isspace(c);

}


// bool fgrade(const Student_info& s)
// {
// 	
// 	return grade(s) < 60;
// 
// }

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), not_space);

		iter j = find_if(i, str.end(), space);

		if (i != str.end())
		{
			ret.push_back(string(i, j));
		}
	}

	return ret;
}

//int main(int, char **, char **)
//{
//	vector<Student_info> students;
//	Student_info record;
//
//	string::size_type maxlen = 0;
//
//	while(read(cin, record))
//	{
//		maxlen = max(maxlen, record.name.size());
//		students.push_back(record);
//	}
//
//	sort(students.begin(), students.end(), compare);
//
//	for (vector<Student_info>::size_type i = 0; i!= students.size(); i++)
//	{
//		cout << setw(maxlen+1) << students[i].name;
//
//		try
//		{
//			double final_grade = grade(students[i]);
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << final_grade
//				<< setprecision(prec);
//		}
//		catch (domain_error e)
//		{
//			cout << e.what();
//		}
//		cout << endl;
//
//	}
//
//	return 0;
//}

struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);

void set_pc(free_throws & ft);

free_throws & accumulate(free_throws & target, const free_throws & source);

//int main()
//{
//	free_throws one = {"Ifelsa Branch", 13, 14};
//	free_throws two = {"Andor Knott", 10, 16};
//	free_throws three = {"Minnie Max", 7, 9};
//	free_throws four = {"Whily Looper", 5, 9};
//	free_throws five = {"Long Long", 6, 14};
//	free_throws team = {"Throwgoods", 0, 0};
//	free_throws dups;
//
//	set_pc(one);
//	display(one);
//	accumulate(team, one);
//	display(team);
//
//	display(accumulate(team, two));
//	accumulate(accumulate(team,three), four);
//	display(team);
//
//	dups = accumulate(team, five);
//	cout << "Displaying team:\n";
//	display(team);
//
//	cout << "Displaying dups after accumulate:\n";
//	display(dups);
//	set_pc(four);
//
//	accumulate(dups, five) = four;
//	cout << "Disaplaying dups after 1ll-advesed assignment:\n"<<endl;
//	display(dups);
//	
//	return 0;
//}


void display(const free_throws & ft)
{
	cout << "Name: " << ft.name << "\n";
	cout << "Made: " << ft.made << "\t";
	cout << "Attempts: " << ft.attempts << "\t";
	cout << "Precent: " << ft.percent << "\n";
}

void set_pc(free_throws &ft)
{
	if (ft.attempts != 0)
	{
		ft.percent = 100.0f * float (ft.made) / float (ft.attempts);
	}
	else
	{
		ft.percent = 0;
	}
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}


const int ArSize = 80;
char * left(const char * str, int n = 1);

int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "Enter a string\n";

	cin.get(sample, ArSize);

	char *ps = left(sample, 4);

	cout << ps << endl;
	delete [] ps;

	ps = left(sample);
	cout << ps << endl;

	delete [] ps;

	return 0;

}


char * left(const char * str, int n)
{
	if (n < 0)
	{
		n = 0;
	}

	char * p = new char[n+1];
	int i;

	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];

	while (i <= n)
		p[i++] = '\0';

	return p;
}