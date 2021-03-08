#include<bits/stdc++.h>
using namespace std;

bool chk_1(char c) {
    return 'a' <= c && c <= 'z';
}

bool chk_2(char c) {
    return 'A' <= c && c <= 'Z';
}

bool chk_3(char c) {
    return '0' <= c && c <= '9';
}

string solution(string new_id) {
    string s = new_id;
    
    for(int i = 0; i < s.length(); i++) {
        if(chk_2(s[i])) {
            s[i] = s[i] - 'A' + 'a';
        }
	}

	string s2;
	
	for(int i = 0; i < s.length(); i++) {
		char c = s[i];
		
		if(chk_1(c) || chk_3(c) || c == '-' || c == '_' || c == '.') {
			s2 += c;
		}
	}
	
	string s3;
	
	bool dot = false;
	
	for(int i = 0; i < s2.length(); i++) {
		char c = s2[i];
		
		if(c == '.' && dot) {
			continue;
		}
		
		s3 += c;
		
		dot = c == '.';
	}
	
	if(!s3.empty() && s3.front() == '.') {
		s3 = s3.substr(1);
	}
	
	if(!s3.empty() && s3.back() == '.') {
		s3.pop_back();
	}
	
	if(s3.empty()) {
		s3 += 'a';
	}
	
	if(s3.size() >= 16) {
		s3 = s3.substr(0, 15);
		
		if(s3.back() == '.') {
			s3.pop_back();
		}
	}
	
	if(s3.size() == 1) {
		s3 = s3 + s3 + s3;
	}
	
	else if(s3.size() == 2) {
		s3 += s3.back();
	}
	
	return s3;
}
