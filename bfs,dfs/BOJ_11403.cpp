#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int result[100][100]={0,};
vector<int> a[100];

void bfs(int start_x, int end_x){
    queue<int> q;
    int v[100]={0,};

    q.push(start_x);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == end_x && v[x]==1){
            result[start_x][end_x] = 1;
            return;
        }

        for (int i = 0; i < a[x].size(); i++){
            int dx = a[x][i];
            if(v[dx]==0){
                q.push(dx);
                v[dx] = 1;
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++){
        for (int x,j = 0; j < n; j++){
            cin >> x;
            if(x==1)
                a[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(result[i][j]==0)
                bfs(i, j);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
