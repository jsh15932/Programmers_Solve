class Solution {
    boolean solution(String s) {
        boolean answer = true;
        int cnt_p = 0, cnt_y = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'p' || s.charAt(i) == 'P') {
                cnt_p++;
            }
            
            else if(s.charAt(i) == 'y' || s.charAt(i) == 'Y') {
                cnt_y++;
            }
        }
        
        if((cnt_p == 0 && cnt_y == 0) || cnt_p - cnt_y == 0 || cnt_y - cnt_p == 0) {
            answer = true;
        }
        
        else {
            answer = false;
        } 

        return answer;
    }
}