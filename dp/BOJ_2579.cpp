#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
int n;
int dp[300][2]={0,};

void solve(){
    int result = 0;
    if (n == 1)
    {
        result = a[0];
    }else{
        dp[0][0] = a[0];
        dp[1][0] = a[1];
        dp[1][1] = a[0] + a[1];
        for (int i = 2; i < n; i++){
            dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
            dp[i][1] = dp[i - 1][0] + a[i];
        }
        result = max(dp[n - 1][0], dp[n - 1][1]);
    }
    cout << result << endl;
}

int main(){
    cin >> n;
    for (int x, i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    solve();
}
