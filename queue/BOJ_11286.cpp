#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int n;
priority_queue<int, vector<int>, compare>pq;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int x,i =0 ; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0 ; i < n; i++){
        int x = v[i];
        if(x==0 && pq.empty())
            cout << "0\n";
        else if(x==0){
            cout << pq.top() <<"\n";
            pq.pop();
        }
        else
        {
            pq.push(x);
        }
    }
        return 0;
}
