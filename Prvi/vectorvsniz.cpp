#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int *A = new int [3];

	A [0] = 1;
	A [1] = 2;
	A [2] = 3;


	for (int i = 0; i < 3; i++)
		cout << A [i] << " ";
	cout << endl;

	return 0;
}

