/*
    우선순위 큐!!
*/
#include <algorithm>
#include <functional> // greater
#include <iostream>
#include <queue>
#include <utility> // pair
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0)
typedef pair<int, char> pic;

int main()
{
    fastio;
    int A, B, N;
    priority_queue<pic, vector<pic>, greater<pic> > pq;
    cin >> A >> B >> N;
    int bBegin, rBegin;
    int bDone = 0, rDone = 0;
    while (N--)
    {
        int t, m;
        char c;
        cin >> t >> c >> m;

        int itemCnt = 0;
        if (c == 'B')
        {
            for (bBegin = max(t, bDone); itemCnt < m; bBegin += A)
            {
                pq.push({bBegin, c});
                itemCnt++;
            }
            bDone = bBegin+A;
        }

        else
        {
            for (rBegin = max(t, rDone); itemCnt < m; rBegin += B)
            {
                pq.push({rBegin, c});
                itemCnt++;
            }
            rDone = rBegin+B;
        }
    }

    vector<int> answerB, answerR;
    int itemIdx = 1;
    while (!pq.empty())
    {
        if (pq.top().second == 'B')
        {
            answerB.push_back(itemIdx++);
        }
        else
        {
            answerR.push_back(itemIdx++);
        }
        pq.pop();
    }

    cout << answerB.size() << '\n';
    for (auto item : answerB)
    {
        cout << item << ' ';
    }
    cout << '\n';

    cout << answerR.size() << '\n';
    for (auto item : answerR)
    {
        cout << item << ' ';
    }
    cout << '\n';
}