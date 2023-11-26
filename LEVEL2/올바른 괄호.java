public class Solution {
    boolean solution(String s) {
        int cnt1 = 0;
        int cnt2 = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                cnt1++;
            }
            
            else if(s.charAt(i) == ')') {
                cnt2++;
            }
            
            if(cnt1 < cnt2) {
                return false;
            }
        }
        
        if(cnt1 == cnt2) {
            return true;   
        }
        
        return false;
    }
}