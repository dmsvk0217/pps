#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> v(21); // index값 1-존재, 0-없음.

void init(){ // 1~20 초기화.
    for (int i = 1; i <= 20; i++){
        v[i] = 1;
    }
}

void arrEmpty(){
    for (int i = 1; i <= 20; i++){
        v[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    string type;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type.compare("all") == 0) init();
        else if (type.compare("empty") == 0) arrEmpty();
        else{
            cin >> x;
            if (type.compare("add") == 0)
            {
                v[x] = 1;
            }
            if (type.compare("remove") == 0)
            {
                v[x] = 0;
            }
            if (type.compare("check") == 0)
            {
                v[x] == 1 ? cout << "1\n" : cout << "0\n";
            }
            if (type.compare("toggle") == 0)
            {
                v[x] == 1 ? v[x] = 0 : v[x] = 1;
            }
        }
    }
}
