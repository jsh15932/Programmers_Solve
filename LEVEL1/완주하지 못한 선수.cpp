#include<string>
#include<map>
#include<vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> mp;
    
    for(auto i : completion) {
        mp[i]++;
    }
    
    for(auto i : participant) {
        mp[i]--;
        
        if(mp[i] < 0) {
            return i;
        }
    }
}