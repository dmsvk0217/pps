#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int fdx[4] = {0, 0, 1, -1};
int fdy[4] = {1,-1,0,0};
int v[100][100]={0,};
string a[100];

bool checkPosition(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n ? true : false;
}

void bfs(int sx, int sy, int option){
    queue<pair<char, pair<int,int>>> q;

    q.push({a[sx][sy], {sx,sy}});
    v[sx][sy] = 1;

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        char w = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++){
            int dx = x + fdx[i];
            int dy = y + fdy[i];
            if(checkPosition(dx,dy) && v[dx][dy] == 0){
                bool canPush = false;
                char dw = a[dx][dy];
                if(w == dw){
                    canPush = true;
                }
                if(option == 1){
                    if((w == 'R' || w == 'G' ) && (dw == 'R' || dw == 'G' )){
                       canPush = true; 
                    }
                }
                if(canPush){
                    q.push({dw, {dx, dy}});
                    v[dx][dy] = 1;
                }
            }
        }
    }
}

void solve(){
    int count = 0;
    int countRG = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if(v[i][j] == 0){
                count++;
                bfs(i,j,0);
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            v[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if(v[i][j] == 0){
                countRG++;
                bfs(i,j,1);
            }
        }
    }
    cout << count << "\n";
    cout << countRG << "\n";
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    solve();
}
