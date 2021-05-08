class Solution {
    public long solution(long n) {
        long answer = 0;
        long idx = 0;
        
        while(idx <= (n / 2) + 1) {
            if(idx * idx == n) {
                answer = (idx + 1) * (idx + 1);
                
                break;
            }
            
            else {
                idx++;
            }
        }
        
        if(answer == 0) {
            answer = -1;
        }
        
        return answer;
    }
}