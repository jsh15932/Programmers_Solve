class Solution {
    public int solution(int num) {
        int answer = 0;
        long a = num;
        
        while(a > 1) {
            if(answer >= 500) {
                answer = -1;
                
                break;
            }
            
            a = a % 2 == 0 ? a / 2 : a * 3 + 1;
            
            answer++;
        }
        
        return answer;
    }
}