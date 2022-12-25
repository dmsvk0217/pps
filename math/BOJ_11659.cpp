#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int n, m;
vector<int> v;
int sum[100001]={0,};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int x,i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    for (int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + v[i-1];
    }

    for (int x, y, i = 0; i < m; i++)
    {
        cin >> x >> y;
        cout << sum[y] - sum[x-1] << "\n";
    }
    return 0;
}
