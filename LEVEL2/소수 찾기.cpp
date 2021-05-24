#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool chk(int n) {
    if(n < 2) {
        return false;
    }
    
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> vc;
    
    for(int i = 0; i < numbers.size(); i++) {
        vc.push_back(numbers[i] - '0');
    }
    
    sort(vc.begin(), vc.end());
    vector<int> ans;
    
    do {
        for(int i = 0; i <= vc.size(); i++) {
            int tmp = 0;
            
            for(int j = 0; j < i; j++) {
                tmp = (tmp * 10) + vc[j];
                ans.push_back(tmp);
            }
        }
    } while(next_permutation(vc.begin(), vc.end()));
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    for(int i = 0; i < ans.size(); i++) {
        if(chk(ans[i])) {
            answer++;
        }
    }
    
    return answer;
}