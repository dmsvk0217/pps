#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
unordered_map<string,string> um;
string s1, s2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s1 >> s2;
        um.insert({s1, s2});
    }

    for (int i = 0; i < m; i++){
        cin >> s1;
        cout << um[s1] << "\n";
    }

    return 0;
}
