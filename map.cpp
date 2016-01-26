#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map <string, int> ocjene;

int main()
{
	ocjene ["elvir"] = 5;
	ocjene ["a"] = 4;
	ocjene ["er"] = 3;
	ocjene ["egasdasdlvir"] = 1;

	for (map <string, int> :: iterator it = ocjene.begin(); it != ocjene.end(); it++)
		cout << it -> first << " " << it -> second << endl;


	return 0;
}
