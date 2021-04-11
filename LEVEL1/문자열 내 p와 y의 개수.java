class Solution {
    boolean solution(String s) {
        boolean answer = true;
        int cnt_p = 0, cnt_y = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'P' || s.charAt(i) == 'p') {
                cnt_p++;
            }
            
            else if(s.charAt(i) == 'Y' || s.charAt(i) == 'y') {
                cnt_y++;
            }
        }
        
        if(cnt_p == cnt_y) {
            answer = true;
        }
        
        else {
            answer = false;
        }

        return answer;
    }
}