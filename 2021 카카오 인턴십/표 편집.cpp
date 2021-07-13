#include<string>
#include<stack>
#include<vector>
using namespace std;

struct C {
	int d;
	C* next;
	C* pre;
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<C*> vc(n);
    stack<int> del;
    
    for(int i = 0; i < n; i++) {
    	vc[i] = new C();
    	vc[i]->d = i;
	}
	
	for(int i = 0; i < n; i++) {
		if(i > 0) {
			vc[i]->pre = vc[i - 1];
		}
		
		if(i < n - 1) {
			vc[i]->next = vc[i + 1];
		}
	}
	
	C* cur = vc[k];
	vector<bool> chk(n, true);
	
	for(int i = 0; i < cmd.size(); i++) {
		if(cmd[i][0] == 'U') {
			int mv = stoi(cmd[i].substr(2));
			
			while(mv-- > 0) {
				cur = cur->pre;
			}
		}
		
		else if(cmd[i][0] == 'D') {
			int mv = stoi(cmd[i].substr(2));
			
			while(mv-- > 0) {
				cur = cur->next;
			}
		}
		
		else if(cmd[i][0] == 'C') {
			del.push(cur->d);
			chk[cur->d] = false;
			
			if(cur->pre) {
				cur->pre->next = cur->next;
			}
			
			if(cur->next) {
				cur->next->pre = cur->pre;
			}
			
			if(cur->next) {
				cur = cur->next;
			}
			
			else {
				cur = cur->pre;
			}
		}
		
		else if(cmd[i][0] == 'Z') {
			int t = del.top();
			del.pop();
			chk[t] = true;
			
			if(vc[t]->pre) {
				vc[t]->pre->next = vc[t];
			}
			
			if(vc[t]->next) {
				vc[t]->next->pre = vc[t];
			}
		}
	}
	
	for(int i = 0; i < chk.size(); i++) {
		if(chk[i]) {
			answer += 'O';
		}
		
		else {
			answer += 'X';
		}
	}
    
    return answer;
}