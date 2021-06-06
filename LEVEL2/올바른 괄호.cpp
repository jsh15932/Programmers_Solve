#include<string>
#include<stack>
#include<vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push('(');
        }
        
        else {
            if(!st.empty() && st.top() == '(') {
                st.pop();
            }
            
            else {
                st.push(')');
            }
        }
    }
    
    if(st.empty()) {
        answer = true;
    }

    else {
        answer = false;
    }
    
    return answer;
}