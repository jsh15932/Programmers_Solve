class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;
        boolean[][] chk = new boolean[n + 1][n + 1];
        
        for(int i = 0; i < results.length; i++) {
            chk[results[i][0] - 1][results[i][1] - 1] = true;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(chk[j][i] && chk[i][k]) {
                        chk[j][k] = true;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                
                if(chk[i][j] || chk[j][i]) {
                    cnt++;
                }
            }
            
            if(cnt == n - 1) {
                answer++;
            }
        }
        
        return answer;
    }
}