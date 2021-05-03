#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int bfs(vector<int> numbers, int target, int sum, int idx) {
    if(idx == numbers.size()) {
        if(sum == target) {
            return 1;
        }
        
        else {
            return 0;
        }
    }
    
    int res = 0;
    res += bfs(numbers, target, sum + numbers[idx], idx + 1);
    res += bfs(numbers, target, sum - numbers[idx], idx + 1);
    
    return res;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = bfs(numbers, target, numbers[0], 1) + bfs(numbers, target, -numbers[0], 1);
    
    return answer;
}