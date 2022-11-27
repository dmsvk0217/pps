#include <iostream>
#include <math.h>

using namespace std;

int a[2200][2200] = {0,};
int count[3] = {0,};

void solve(int x, int y, int n){
    if(n==1){
        if(a[x][y] == -1)
            ::count[0]++;
        if(a[x][y] == 0)
            ::count[1]++;
        if(a[x][y] == 1)
            ::count[2]++;
        return;
    }

    int target = a[x][y];
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++){
            if(target != a[i][j]){
                int d = n / 3;
                for (int c = 0; c < d * 3; c+=d){
                    for (int l = 0; l < d * 3; l += d)
                    {
                        int dx = x + c;
                        int dy = y + l;
                        solve(dx, dy, d);
                    }
                }
                return;
            }
        }
    }

    if(a[x][y] == -1)
        ::count[0]++;
    if(a[x][y] == 0)
        ::count[1]++;
    if(a[x][y] == 1)
        ::count[2]++;

    return;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    solve(0,0,n);

    for (int i = 0; i < 3; i++){
        cout << ::count[i] << "\n";
    }
}
