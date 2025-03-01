#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int n;
string a, b;

map <string, string> people;
map <string, vector <string> > parents;

void resolve(string child, string parent1, string parent2)
{
	if (people.find(parent1) == people.end())
		resolve(parent1, parents [parent1] [0], parents [parent1] [1]);

	if (people.find(parent2) == people.end())
		resolve(parent2, parents [parent2] [0], parents [parent2] [1]);

	bool has_gene = false;

    if (people[parent1] != "non-existent" && people[parent2] != "non-existent")
        has_gene = true;
    else if (people [parent1] == "dominant" || people [parent2] == "dominant") 
        has_gene = true;

	if (has_gene)
	{
		if ((people [parent1] == "dominant" || people [parent2] == "dominant") && 
			(people [parent1] != "non-existent" && people [parent2] != "non-existent"))
			people [child] = "dominant";
		else
			people [child] = "recessive";
	}
	else
		people [child] = "non-existent";
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		if (b == "non-existent" || b == "recessive" || b == "dominant")
			people [a] = b;
		else
			parents [b].push_back(a);
	}

	//for (map <string, vector <string> >::iterator it = parents.begin(); it != parents.end(); it++) ok
	for (auto it = parents.begin(); it != parents.end(); it++)
	//for (auto person : parents)
	{
		resolve (it->first, it->second [0], it->second [1]);
	}

	for (auto person : people)
		cout << person.first << " " << person.second << endl;


	return 0;
}
