#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<int> s;
set<int> init;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 20; i++)
        init.insert(i);

    int n; cin >> n;
    string type;
    int x;

    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type.compare("all") == 0)
        {
            s = init;
        }else if (type.compare("empty") == 0)
        {
            s = {};
        }else{
            cin >> x;
            if (type.compare("add") == 0)
            {
                s.insert(x);
            }
            if (type.compare("remove") == 0)
            {
                s.erase(x);
            }
            if (type.compare("check") == 0)
            {
                s.find(x)!=s.end() ? cout << "1\n" : cout << "0\n";
            }
            if (type.compare("toggle") == 0)
            {
                if(s.find(x)!=s.end()){ // 있는 경우 삭제
                    s.erase(s.find(x));
                }
                else
                { // 없는 경우 추가
                    s.insert(x);
                }
            }
        }
    }
}
