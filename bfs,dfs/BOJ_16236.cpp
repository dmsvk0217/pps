#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int space[20][20]={0,};
int sx, sy;
int bs_size = 2;
int get_fish = 0;
int result = 0;

int fdx[4] = {-1, 0, 0, 1};
int fdy[4] = {0, -1, 1, 0};

bool pass(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

void cal(int tx, int ty, int d_result){
    sx = tx;
    sy = ty;
    result += d_result;
    get_fish++;
    space[tx][ty] = 0;


    if (bs_size == get_fish)
    {
        bs_size++;
        get_fish = 0;
    }
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    int ax = a.first.first;
    int ay = a.first.second;
    int bx = b.first.first;
    int by = b.first.second;
    int resa = a.second;
    int resb = b.second;
    
    if (resa == resb && ax == bx)
        return ay < by;
    if(resa == resb)
        return ax < bx;
    return resa < resb;
}

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    vector<pair<pair<int, int>, int>> go;
    int v[20][20]={0,};

    q.push({{sx, sy}, 0});
    v[sx][sy] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d_result = q.front().second;
        q.pop();

        if(space[x][y] && bs_size > space[x][y])
            go.push_back({{x, y}, d_result});


        for (int i = 0; i < 4; i++)
        {
            int dx = x + fdx[i];
            int dy = y + fdy[i];
            if (pass(dx, dy) && v[dx][dy] == 0 && bs_size >= space[dx][dy])
            {
                q.push({{dx, dy}, d_result+1});
                v[dx][dy] = 1;
            }
        }
    }

    if(go.size() == 0){
        return 0;
    }
    else
    {
        sort(go.begin(), go.end(), cmp);

        int x = go[0].first.first;
        int y = go[0].first.second;
        int d_result = go[0].second;

        cal(x, y, d_result);
        return 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> space[i][j];
            if (space[i][j] == 9)
            {
                sx = i;
                sy = j;
            }
        }
    }

    space[sx][sy] = 0;

    while(bfs()){};
    cout << result << endl;
    
    return 0;
}
