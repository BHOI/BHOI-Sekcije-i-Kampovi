#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

vector <int> A = { 3, 1, 2 };
int B [3] = { 3, 1, 2 };

int main()
{
	ios_base :: sync_with_stdio(false);

/*
 * ista funkcija, razliciti parametri
 */
	sort (A.begin(), A.end());
	sort (B, B + 3);

	cout << "A: ";
	for (int i = 0; i < 3; i++)
		cout << A [i] << " ";

	cout << endl;

	cout << "B: ";
	for (int i = 0; i < 3; i++)
		cout << B [i] << " ";

	reverse (A.begin(), A.end());
	reverse (B, B + 3);

	cout << endl;

	cout << "A: ";
	for (int i = 0; i < 3; i++)
		cout << A [i] << " ";

	cout << endl;

	cout << "B: ";
	for (int i = 0; i < 3; i++)
		cout << B [i] << " ";

	char ime [20], prezime [20], godina;
	float nesto [12];

	while (fscanf (in, "%s", ime) == 1)
	{
		int i;
		fscanf (in, "%s %d", prezime, &godina);
		for (i = 0; i < 12; i++)
			fscanf (in, "%f", &nesto [i]);
	}

	return 0;
}
