#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int K;
    cin >> K;

    stack<int> s;
    int sum = 0;
    while(K--){
        int money;
        cin>>money;
        if(money == 0){ sum-=s.top(); s.pop();}
        else{ s.push(money); sum += s.top();}
    }
    cout<<sum;
}
