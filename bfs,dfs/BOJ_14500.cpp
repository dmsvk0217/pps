#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[502][502] ={0,}; // 0~501 1~500에 저장.
int v[502][502] ={0,};
int answer = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int isPass(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void dfs(int x, int y, int score, int depth){
    if(depth==4){
        answer = max(answer, score);
        return;
    }

    for (int i = 0; i < 4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (isPass(tx, ty) && v[tx][ty] == 0)
        {
            v[tx][ty] = 1;
            dfs(tx, ty, score+board[tx][ty], depth+1);
            v[tx][ty] = 0;
        }
    }
}

void blockChect(int x, int y){
    for (int i = 0; i < 4; i++){
        // i - 무시할 방향.
        int score = board[x][y];
        for (int j = 0; j < 4; j++)
        {
            int tx = x + dx[j];
            int ty = y + dy[j];
            if(i != j){
                score += board[tx][ty];
            }
        }
        answer = max(answer, score);
    }B
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            v[i][j]=1;
            dfs(i, j, board[i][j], 1);
            v[i][j]=0;

            blockChect(i, j);
        }
    }

    cout << answer << endl;

    return 0;
}
