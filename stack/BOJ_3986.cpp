#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int count = 0;
    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        string a;
        stack<char> st;
        cin >> a;
        for (int i = 0; i < a.length(); i++){
            if(st.empty()){
                st.push(a[i]);
            }else if(st.top() == a[i]){
                st.pop();
            }else{
                st.push(a[i]);
            }
        }
        if(st.empty()){
            count++;
        }
    }
    cout << count << endl;
}
