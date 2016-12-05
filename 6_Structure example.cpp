#include <iostream>
#include <string>

using namespace std;

struct SimpleClass{
private:
	int Count_of_learners = 0;
	string Names[100];
	int Skills[100];
public:
	int CountOfLearners(){
		return Count_of_learners;
	}
	void Add(string First_name, string Second_name, int Skill_of_learner){
		Names[Count_of_learners] = Second_name + " " + First_name;
		Skills[Count_of_learners] = Skill_of_learner;
		Count_of_learners++;
	}
	string GetNameForNumber(int number){
		return Names[number];
	}
	int GetSkillForNumber(int number){
		return Skills[number];
	}
};

int main()
{
	SimpleClass MyClass;
	cout << "Write count of learners: ";
	int n;
	cin >> n;
	cout << "Write: First_name Second_name skill" << endl;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		int x;
		cin >> a >> b >> x;
		MyClass.Add(a, b, x);
	}
	cout << endl;
	for (int i = 0; i < MyClass.CountOfLearners(); i++)
	{
		cout << MyClass.GetNameForNumber(i);
	    cout << " " << MyClass.GetSkillForNumber(i) << endl;
	}
	return 0;
}