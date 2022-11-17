#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
unordered_map<string, int> no_heard;
vector<string> result;
int main()
{
    int count = 0;
    cin >> n >> m;
    for (int i = 0; i<n; i++){
        string a;
        cin >> a;
        no_heard.insert({a, i});
    }
    for (int i = 0; i<m; i++){
        string a;
        cin >> a;
        if(no_heard.find(a)!=no_heard.end()){//존재하면
            count++;
            result.push_back(a);
        }
    }
    sort(result.begin(), result.end());

    cout << count << "\n";
    for (int i = 0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
}
/*
내부적으로 hash로 구현되어있는 자료구조인 unordered_map을 이용했다.

최대의 경우 50만개의 듣지못한 문자열과 50만개의 보지못한 문자열을 비교해야 한다.
문자의 길이는 20으로 그리 길지 않지만 문자열 자체의 갯수가 단순 비교를 통해서는 시간이 오버된다.
그래서 hash 기반 unordered_map 통해서 key값을 통해 O(1)로 접근해야한다고 생각했다.
*/
