class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 1;
        int x = 0;
        int y = 0;
        
        if(a > b) {
            x = b;
            y = a;
        }
        
        else {
            x = a;
            y = b;
        }
        
        while(true) {
            if(x % 2 != 0 && y - x == 1) {
                break;
            }
            
            x = (x + 1) / 2;
            y = (y + 1) / 2;
            answer++;
        }
        
        return answer;
    }
}