#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string str;
    vector<int> res;
    int result = 0;
    cin >> n >> m >> str;

    int count = 0;
    bool pass = true;
    for (int i = 0; i < str.size(); i++){
        if ((pass && str[i] == 'I') || (!pass && str[i] == 'O'))
        {
            count++;
            pass = !pass;
        }
        else if(str[i] == 'I')
        {
            if(2*n+1 <= count){
                if(str[i]=='O')
                    count--;
                res.push_back(count);
            }
            count = 1;
            pass = false;
        }else{
            if(2*n+1 <= count){
                if(str[i]=='O')
                    count--;
                res.push_back(count);
            }
            count = 0;
            pass = true;
        }
    }
    if(2*n+1 <= count)
        res.push_back(count);

    for (int i = 0; i < res.size(); i++){
        result += (res[i] - (n * 2 - 1)) / 2;
    }
    cout << result << "\n";
    return 0;
}
