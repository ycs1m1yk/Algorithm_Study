#include <iostream>
#include <utility>
#include <stack>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(){
    fastio;
    
    int N, op, A, T;
    int score=0;
    stack<pair<int,int>> taskStack;
    cin>>N;

    while(N--){
        cin >> op;
        if(!op && !taskStack.empty()){
            taskStack.top().second--;            
            if(taskStack.top().second == 0){
                score+=taskStack.top().first;
                taskStack.pop();
            }
        }
        else if(op){
            cin>>A>>T;
            if(T==1) 
                score+=A;
            else
                taskStack.push(make_pair(A,T-1));
                
        }
    }
    cout<<score;
}