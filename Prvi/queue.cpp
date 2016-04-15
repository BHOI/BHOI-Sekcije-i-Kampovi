#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	queue <int> q;

	q.push(1);
	cout << "front: " << q.front() << " back: " << q.back() << endl;
	q.push(2);
	cout << "front: " << q.front() << " back: " << q.back() << endl;
	q.push(3);
	cout << "front: " << q.front() << " back: " << q.back() << endl;
	q.push(4);
	cout << "front: " << q.front() << " back: " << q.back() << endl;

	q.pop();
	cout << "front: " << q.front() << " back: " << q.back() << endl;

	//ako zelimo da iteriramo kroz queue, onda ne zelimo raditi sa queue

	return 0;
}
