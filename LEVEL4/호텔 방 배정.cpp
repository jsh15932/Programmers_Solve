#include<bits/stdc++.h>
using namespace std;

map<long long, long long> mp;

long long find(long long n) {
    if(mp[n] == 0) {
        return n;
    }
    
    return mp[n] = find(mp[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i = 0; i < room_number.size(); i++) {
        long long num = room_number[i];
        
        if(mp[num] == 0) {
            answer.push_back(num);
            mp[num] = find(num + 1);
        }
        
        else {
            long long next = find(num);
            answer.push_back(next);
            mp[next] = find(next + 1);
        }
    }
    
    return answer;
}