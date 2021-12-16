#include <iostream>
#include <queue>
using namespace std;

// 사용자 정의 비교함수
struct cmp
{
    bool operator()(int l, int r)
    {
        // heap 자료구조를 사용하는것을 알 수 있음.
        cout << "l=" << l << ", r=" << r << "\n";
        return l > r;
    }
};

int main()
{
    /*
        STL 우선순위큐는 힙을 사용하지만 unstable
    */
    priority_queue<int> pq;
    priority_queue<int, vector<int>, cmp> pq_g;

    pq.push(20);
    pq.push(15);
    pq.push(13);
    pq.push(5);
    pq.push(7);
    pq.push(8);
    pq.push(4);

    priority_queue<int> pq2{pq};
    for (cout << "pq2 : "; !pq2.empty(); pq2.pop())
    {
        cout << pq2.top() << " ";
        /*
            output: "pq2 : 20 15 13 8 7 5 4"
            if stable(unorderd): "pq2 : 20 15 13 5 7 8 4"
        */
    }
    cout << "\n";

    pq.pop();
    for (cout << "pq : "; !pq.empty(); pq.pop())
    {
        cout << pq.top() << " ";
    }
    cout << "\n";

    pq_g.push(49);
    pq_g.push(144);
    pq_g.push(22);
    pq_g.push(1);
    pq_g.push(77);

    for (cout << "pq_g : "; !pq_g.empty(); pq_g.pop())
    {
        cout << pq_g.top() << " ";
    }
}