#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

unordered_map<string, int> list_name;
unordered_map<int, string> list_number;
vector<string> quiz;
int n, m;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string str;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> str;
        list_name.insert({str, i});
        list_number.insert({i, str});
    }

    for (int i = 1; i <= m; i++){
        cin >> str;
        quiz.push_back(str);
    }

    for (int i = 0; i < m; i++){
        if(isdigit(quiz[i][0]) != 0){
            int num = stoi(quiz[i]);
            cout << list_number[num] << "\n";
        }else{
            cout << list_name[quiz[i]] << "\n";
        }
    }
}

/*
unordered_map : hash 기반의 map. crud O(1)를 가짐. 많은 데이터를 저장할때 사용.

stoi(string to integer) : string에 문자가 있으며 오류 발생. 문자열로된 순수 숫자로 이루어져있어야함.
atio() : c에서의 stoi

isdigit : string 전체가 아니라 char 인덱스 하나만 받아서 판별함.
*/
