#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[64][64]={0,};
vector<char> v;

void solve(int x, int y, int n){
    int target = a[x][y];
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++){
            if(target != a[i][j]){
                v.push_back('(');
                solve(x, y, n / 2);
                solve(x, y + n / 2, n / 2);
                solve(x + n / 2, y, n / 2);
                solve(x + n / 2, y + n / 2, n / 2);
                v.push_back(')');
                return;
            }
        }
    }

    char temp = (char)target;
    v.push_back(temp);
    return;
}

int main(){
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> str;
        for (int j = 0; j < n; j++){
            a[i][j] = str[j];
        }
    }

    solve(0,0,n);

    for (int i = 0; i < v.size(); i++){
        cout << v[i];
    }
}
