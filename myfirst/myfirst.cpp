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

int main(int, char **, char **)
{
	vector<Student_info> students;
	Student_info record;

	string::size_type maxlen = 0;

	while(read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i!= students.size(); i++)
	{
		cout << setw(maxlen+1) << students[i].name;

		try
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;

	}

	return 0;
}