#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    getchar();

    while(T--){
        char c;
        stack<char> s;
        while((c=getchar()) != '\n'){
            if(c==')' && !s.empty() && s.top()=='(')
                s.pop();
            else
                s.push(c);
        }
        printf( s.empty() ? "YES\n" : "NO\n");
    }
}
