#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    while(1){ // if same, return 0
        stack<int> st;
        string input;
        bool res= true;
        getline(cin, input);
        if(input.compare(".") == 0) break;
        
        for(int i=0; i<input.length(); i++){
            if(input[i] == '(' || input[i] == '['){
                st.push(input[i]);
            }
            if(input[i] == ')'){
                if(st.empty()){
                    res = false;
                }else if(st.top() == '('){
                    st.pop();
                }else{
                    res = false;
                }
            }
            if(input[i] == ']'){
                if(st.empty()){
                    res = false;
                }else if(st.top() == '['){
                    st.pop();
                }else{
                    res = false;
                }
            }
        }
        if(!st.empty()) res = false;
        
        if(res) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
