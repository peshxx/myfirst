#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

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

// vector<Student_info> extract_fails(vector<Student_info>& students)
// {
// 	vector<Student_info> pass,fail;
// 
// 	for (vector<Student_info>::size_type i = 0;
// 		i != students.size(); i++)
// 	{
// 			if (fgrade(students[i]))
// 				fail.push_back(students[i]);
// 			else
// 				pass.push_back(students[i]);
// 	}
// 
// 	students = pass;
// 
// 	return fail;
// }

int main(int, char **, char **)
{
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello" << name << " !" << endl;

	cout << "Please inter your midteam and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Please inter your homework grades: ";
	vector<double> homework;
	double x;

	while(cin >> x)
	{
		homework.push_back(x);
	}

	typedef vector<double>::size_type vec_sz;

	vec_sz size = homework.size();

	if (size == 0)
	{
		cout << endl << "Your must enter your grades. "
			<<"Please try again." <<endl;
		return 1;
	}

	sort(homework.begin(), homework.end());

	vec_sz mid = size/2;

	double median;

	median = (size%2 == 0) ? (homework[mid] + homework[mid-1]) / 2 
		:homework[mid];

	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) <<endl;

	return 0;
}