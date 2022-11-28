#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#define INF 987654321
#define NODEN 126

using namespace std;

int a[NODEN][NODEN];
int dist[NODEN][NODEN];
int fdx[4] = {0, 0, 1, -1};
int fdy[4] = {1, -1, 0, 0};
int n;

void dijkstra(int sx, int sy){
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({-a[sx][sy], {sx, sy}});
    dist[sx][sy] = a[sx][sy];
    
    while (!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int w = -pq.top().first;
        pq.pop();

        if(w > dist[x][y]) continue;

        for (int i = 0; i < 4; i++){
            int dx = x + fdx[i];
            int dy = y + fdy[i];
            int dw = w + a[dx][dy];
            
            if (dx > 0 && dy > 0 && dx <= n && dy <= n)
            { 
                if (dist[dx][dy] > dw)
                {
                    dist[dx][dy] = dw;
                    pq.push({-dw, {dx, dy}});
                }
            }
        }
    }
}

int main(){
    int t = 0;
    while (1)
    {
        t++;
        cin >> n;
        if(n==0)
            break;
        for (int i = 1; i <= n; i++)
        {
            for (int d,j = 1; j <= n; j++){
                cin >> d;
                a[i][j] = d;
            }
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist[i][j] = INF;
            }
        }

        dijkstra(1, 1);

        printf("Problem %d: %d\n", t, dist[n][n]);
    }
}
