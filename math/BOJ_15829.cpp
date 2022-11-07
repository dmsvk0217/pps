#include <iostream>
#include <vector>
#include <string>

using namespace std;

string input;
int n;

void solve(){
    long long res = 0, m = 1234567891, r=1;

    for (int i = 0; i < n; i++){
        int a = input[i] - 'a' + 1;
        res = (res + (a * r)) % m;
        r = (r * 31) % m;
    }

    cout << res;
}
int main(){
    scanf("%d", &n);
    cin >> input;

    solve();
    return 0;
}
