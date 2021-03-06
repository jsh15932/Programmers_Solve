class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        int[][] dp = new int[n + 1][m + 1];
        dp[1][1] = 1;
        
        for(int[] p : puddles) {
            dp[p[1]][p[0]] = -1;
        }
        
        for(int i = 1; i < dp.length; i++) {
            for(int j = 1; j < dp[i].length; j++) {
                if(dp[i][j] == -1) {
                    dp[i][j] = 0;
                }
                
                else {
                    if(i == 1) {
                        dp[i][j] += dp[i][j - 1];
                    }
                    
                    else {
                        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
                    }
                }
                
                if(j == dp[i].length - 1) {
                    answer = dp[i][j];
                }
            }
        }
        
        return answer;
    }
}