#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;

    for(int i = 0; i <5; i++){
        s.push(i);
    }    
    cout << "top element : " << s.top() << "\n";
    cout << "stack size : " << s.size() << "\n";
    cout << "It is empty? : " << (s.empty() ? "Yes" : "No") << "\n";

    for (int i = 0; i < 2; i++)
    {
        s.pop();
    }
    cout << "top element : " << s.top() << "\n";
    cout << "stack size : " << s.size() << "\n";
    cout << "It is empty? : " << (s.empty() ? "Yes" : "No") << "\n";

}