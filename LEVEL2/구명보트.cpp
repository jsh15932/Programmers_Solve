#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int idx = 0;
    
    while(idx < people.size()) {
        int p = people.back();
        people.pop_back();
        
        if(people[idx] + p <= limit) {
            idx++;
            answer++;
        }
        
        else {
            answer++;
        }
    }
    
    return answer;
}