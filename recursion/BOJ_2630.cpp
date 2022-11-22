#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int a[128][128]={0,};
int white = 0;
int blue = 0;

void solve(int x, int y, int n){

    if (n == 1){
        if(a[x][y] == 1) blue++;
        if(a[x][y] == 0) white++;
        return ;
    }

    bool res = true;
    for (int i = x; i < x+n; i++)
    {
        for (int j = y; j < y+n;  j++){
            if(a[i][j] != a[x][y]){
                res = false;
            }
        }
    }

    if(res){
        if(a[x][y] == 1) blue++;
        if(a[x][y] == 0) white++;
        return ;
    }else{
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
        return;
    }
    return;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    solve(0, 0, n);

    cout << white << endl;
    cout << blue << endl;
}
