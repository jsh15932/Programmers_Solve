#include<bits/stdc++.h>
using namespace std;

string change(int n, int k) {
    int m = n / k;
    int r = n % k;
    
    if(m > 0) {
        return change(m, k) + to_string(r);
    }
    
    else {
        return to_string(r);
    }
}

bool isPrimeNumber(long long n) {
    if(n == 2 || n == 3 || n == 5 || n == 7) {
        return true;
    }
    
    if(n == 1 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
        return false;
    }
    
    for(int i = 11; i <= (long long)sqrt(n); i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}


int solution(int n, int k) {
    int answer = 0;
    string s = k == 10 ? to_string(n) : change(n, k);
    stringstream ss(s);
    string c;
    
    while(getline(ss, c, '0')) {
        if(c.size() > 0 && isPrimeNumber(stol(c))) {
            answer++;
        }
    }
    
    return answer;
}