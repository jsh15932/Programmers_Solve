#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vc;
    
    for(auto i : numbers) {
        vc.push_back(to_string(i));
    }
    
    sort(vc.begin(), vc.end(), cmp);
    
    if(vc.at(0) == "0") {
        return "0";
    }
    
    for(auto i : vc) {
        answer += i;
    }
    
    return answer;
}