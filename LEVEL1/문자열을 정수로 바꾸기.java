class Solution {
    public int solution(String s) {
        int answer = 0;
        boolean chk = true;
        int res = 0;
        
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if(c == '-') {
                chk = false;
            }
            
            else if(c != '+') {
                res = res * 10 + (c - '0');
            }
        }
        
        if(chk) {
            answer = res;
        }
        
        else {
            answer = -1 * res; 
        }
        
        return answer;
    }
}