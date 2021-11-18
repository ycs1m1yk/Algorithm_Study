#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }

    cout << "front element : " << q.front() << "\n";
    cout << "back element : " << q.back() << "\n";
    cout << "queue size : " << q.size() << "\n";
    cout << "It is empty? : " << (q.empty() ? "Yes" : "No") << "\n";

    for (int i = 0; i < 2; i++)
    {
        q.pop();
    }

    cout << "front element : " << q.front() << "\n";
    cout << "back element : " << q.back() << "\n";
    cout << "queue size : " << q.size() << "\n";
    cout << "It is empty? : " << (q.empty() ? "Yes" : "No") << "\n";
}