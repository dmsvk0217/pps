#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, int target){
    queue<pair<int, string>> q;
    int v[10000] = {0,};

    q.push({n, ""});
    v[n] = 1;

    int i = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        string res = q.front().second;
        q.pop();

        if (x == target)
        {
            cout << res << "\n";
            break;
        }

        int d_num = (x * 2) % 10000;
        if (v[d_num] == 0)
        {
            q.push({d_num, res+"D"});
            v[d_num] = 1;
        }

        int s_num = x - 1 < 0 ? 9999 : x - 1;
        if (v[s_num] == 0)
        {
            q.push({s_num, res+"S"});
            v[s_num] = 1;
        }

        int temp = x;
        int d1 = temp / 1000;
        temp = temp % 1000;
        int d2 = temp / 100;
        temp = temp % 100;
        int d3 = temp / 10;
        temp = temp % 10;
        int d4 = temp;

        int l_num = d2 * 1000 + d3 * 100 + d4 * 10 + d1 * 1;
        if(v[l_num]==0){
            q.push({l_num, res+"L"});
            v[l_num] = 1;
        }

        int r_num = d4 * 1000 + d1 * 100 + d2 * 10 + d3 * 1;
        if(v[r_num]==0){
            q.push({r_num, res+"R"});
            v[r_num] = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    int n, target;
    while (t--)
    {
        cin >> n >> target;
        bfs(n, target);
    }

    return 0;
}
