#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	stack <int> s;

	/* nece se kompajlirati jer satck nema .back() funkciju implementiranu */
/*
	s.push(1);
	cout << "front: " << s.top() << " back: " << s.back() << endl;
	s.push(2);
	cout << "front: " << s.top() << " back: " << s.back() << endl;
	s.push(3);
	cout << "front: " << s.top() << " back: " << s.back() << endl;
	s.push(4);
	cout << "front: " << s.top() << " back: " << s.back() << endl;

	s.pop();
	cout << "front: " << s.top() << " back: " << s.back() << endl;
*/

	s.push(1);
	cout << "front: " << s.top() << endl;
	s.push(2);
	cout << "front: " << s.top() << endl;
	s.push(3);
	cout << "front: " << s.top() << endl;
	s.push(4);
	cout << "front: " << s.top() << endl;

	s.pop();
	cout << "front: " << s.top() << endl;


	return 0;
}

