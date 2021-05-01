class Solution {
    public int solution(String name) {
        int answer = 0;
        int res = name.length() - 1;
        
        for(int i = 0; i < name.length(); i++) {
            answer += Math.min(name.charAt(i) - 'A', 'Z' - name.charAt(i) + 1);
            int next = i + 1;
        
            while(next < name.length() && name.charAt(next) == 'A') {
                next++;
            }

            res = Math.min(res, i + name.length() - next + i);
        }
        
        answer += res;
        
        return answer;
    }
}