#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    while(t--){
        string inst, str, buffer;
        char delim = ',';
        deque<string> nums;
        int n, front_count = 0, back_count = 0;
        bool isReverse = false;

        cin >> inst >> n >> str; 

        //str splite
        str = str.substr(1, str.size() - 2);
        stringstream f(str);
        while (getline(f, buffer, delim))
        {
            nums.push_back(buffer);
        }

        //inst 순회하며 카운팅.
        for (int i = 0; i < inst.size(); i++)
        {
            if(inst[i]=='R')
                isReverse = !isReverse;
            else{
                if(isReverse)
                    back_count++;
                else
                    front_count++;
            }
        }

        //result print
        if (back_count + front_count > nums.size())
        {
            cout << "error" << endl;
        }
        else
        {
            string result = "[";
            bool isFirst = true;

            //nums pop
            for (int i = 0; i < front_count; i++)
                nums.pop_front();
            for (int i = 0; i < back_count; i++)
                nums.pop_back();

            //result string 만들기
            if(isReverse){
                for (int i = nums.size() - 1; i >= 0; i--)
                {
                    if(!isFirst){
                        result += ",";
                    }else{
                        isFirst = false;
                    }
                    result += nums[i];
                }
            }else{
                for (int i = 0; i < nums.size(); i++){
                    if(!isFirst){
                        result += ",";
                    }else{
                        isFirst = false;
                    }
                    result += nums[i];
                }
            }
            //print
            result += "]";
            cout << result << "\n";
        }
    }
    return 0;
}
