#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    vector<int> a[101];
    // input
    cin >> n >> m;
    for (int x,y,i = 0; i < m; i++){
        cin >> x >> y;
        a[x].push_back(y); // 쌍방향
        a[y].push_back(x);
    }

    // bfs
    queue<int> q;
    int v[101]={0,};

    q.push(1);
    v[1] = 1;
    int count = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); i++){
            int y = a[x][i];
            if(v[y] == 0){
                q.push(y);
                count++;
                v[y] = 1;
            }
        }
    }
    cout << count << "\n";
}
