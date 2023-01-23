#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while(t--){
        map<string, int> m;
        int n;
        int result = 1;

        cin >> n;
        for (int i = 0; i < n; i++){
            string a, b;
            cin >> a >> b;
            m[b]++;
        }

        for (auto i : m){
            result *= (i.second + 1);
        }

        cout << result - 1 << "\n";
    }
}
