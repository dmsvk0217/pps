#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;
vector<pair<int,int>> ladder;
vector<pair<int,int>> snack;

struct cmp{
    bool operator()(pair<int,int> &a, pair<int,int>&b){
        return a.second > b.second;
    }
};

int isLadder(int x){
    for (int i = 0; i < ladder.size(); i++){
        if(x == ladder[i].first)
            return ladder[i].second;
    }
    return 0;
}

int isSnack(int x){
    for (int i = 0; i < snack.size(); i++){
        if(x == snack[i].first)
            return snack[i].second;
    }
    return 0;
}

int bfs(){
    //visit count가 낮은 값부터 탐색
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    int v[110]={0,};
    int start = 1;

    pq.push({start, 0});
    v[start] = 1;

    while(!pq.empty()){
        int x = pq.top().first;
        int count = pq.top().second;
        pq.pop();

        // 도착한 경우
        if(x == 100) return count;
        if(x > 100) continue;

        int isLadder_result = isLadder(x);
        int isSnack_result = isSnack(x);

        //사디리인 경우
        if(isLadder_result){
            pq.push({isLadder_result, count});
            v[isLadder_result] = 1;
            continue;
        }
        //뱀인 경우
        if(isSnack_result){
            pq.push({isSnack_result, count});
            v[isSnack_result] = 1;
            continue;
        }

        //주사위 돌려 이동하기.
        for (int i = 1; i <= 6; i++){
            
            int dx = x + i;

            if(v[dx] == 1) continue;
            pq.push({dx, count + 1});
            v[dx] = 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int x,y,i = 0; i < n; i++){
        cin >> x >> y;
        ladder.push_back({x, y});
    }
    for (int x,y,i = 0; i < m; i++){
        cin >> x >> y;
        snack.push_back({x, y});
    }
    cout << bfs();

    return 0;
}
