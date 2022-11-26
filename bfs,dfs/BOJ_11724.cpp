#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int count = 0;
vector<int> a[1001];
int v[1001] = {
    0,
};

void bfs(int start){
    if(v[start] == 1)
        return;

    queue<int> q;
    q.push(start);
    v[start] = 1;
    ::count++;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); i++){
            int y = a[x][i];
            if(v[y] == 0){
                v[y] = 1;
                q.push(y);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int x,y,i = 0; i < m; i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        bfs(i);
    }
    cout << ::count << "\n";
}
