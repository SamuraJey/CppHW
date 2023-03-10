#include <string>
#include <iostream>

using namespace std;

class Student
{
public:

	string name;
	int group;
	int grades[5];
private:

};

void Sort(Student* stud, int& len)
{
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (stud[i].group > stud[j].group) {
				Student buf = stud[i];
				stud[i] = stud[j];
				stud[j] = buf;
			}
		}
	}
}

double avg(Student st) {
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += st.grades[i];
	}
	return sum / 5;
}

int main()
{
	int sum = 0;
	int ind;
	bool flag = 0;
	int n = 0;
	cin >> n;
	Student* ListOfStudents = new Student[n];
	for (int i = 0; i != n; i++)
	{
		cout << "Input name of student" << endl;
		cin >> ListOfStudents[i].name;
		cout << "Input group of student" << endl;
		cin >> ListOfStudents[i].group;
		cout << "Input grades of student" << endl;
		int j = 0;
		do
		{
			cout << "Grade number" << j + 1 << endl;
			cin >> ListOfStudents[i].grades[j];
			j++;
		} while (j != 5);
	}

	Sort(ListOfStudents, n);

	cout << "Students with average grades >4.2" << endl;
	for (int i = 0; i < n; i++)
		if (avg(ListOfStudents[i]) > 4.2) 
		{
			flag = 1;
			ind = i;
			cout << ListOfStudents[ind].name << endl;
			cout << ListOfStudents[ind].group << endl;
		}
	if (not flag) 
	{
		cout << "No" << endl;
	}
	delete[]ListOfStudents;
	return 0;
}