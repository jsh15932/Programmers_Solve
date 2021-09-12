#include<bits/stdc++.h>
using namespace std;
#define max 360000

int time_to_int(string s) {
    string h = s.substr(0, 2);
    int hour = stoi(h) * 3600;
    string m = s.substr(3, 2);
    int min = stoi(m) * 60;
    string se = s.substr(6, 2);
    int sec = stoi(se);
    
    return hour + min + sec;
}

string time_to_string(int t) {
    string s = "";
    int hour = t / 3600;
    int min = (t % 3600) / 60;
    int sec = t % 60;
    
    if(hour <= 9) {
        s += '0';
    }
    
    s += to_string(hour);
    s += ':';
    
    if(min <= 9) {
        s += '0';
    }
    
    s += to_string(min);
    s += ':';
    
    if(sec <= 9) {
        s += '0';
    }
    
    s += to_string(sec);
    
    return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int play = time_to_int(play_time);
    int adv = time_to_int(adv_time);
    vector<int> total_play(max, 0);
    
    for(int i = 0; i < logs.size(); i++) {
        int start = time_to_int(logs[i].substr(0, 8));
        int end = time_to_int(logs[i].substr(9, 8));
        
        for(int j = start + 1; j <= end; j++) {
            total_play[j]++;
        }
    }
    
    long long int cur_time = 0;
    long long int max_time = 0;
    int t = 1;
    
    for(int i = 1; i <= adv; i++) {
        cur_time += total_play[i];
        max_time += total_play[i];
    }
    
    for(int i = 2; i <= (play - adv + 1); i++) {
        cur_time += (long long int)(total_play[i + adv - 1] - total_play[i - 1]);
        
        if(cur_time > max_time) {
            max_time = cur_time;
            t = i;
        }
    }
    
    answer = time_to_string(t - 1);
    
    return answer;
}