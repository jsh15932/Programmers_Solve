import java.io.*;
import java.util.*;

class Solution {
    public String solution(int a, int b) {
        String answer = "";
        
        int day_30 = 30;
        int day_31 = 31;
        int day = 0;
        int arr[] = {day_31, 29, day_31, day_30, day_31, day_30, day_31, day_31, day_30, day_31, day_30, day_31};
        String[] s = {"THU", "FRI", "STA", "SUN", "MON", "TUE", "WED"};
        
        for(int i = 0; i < a - 1; i++) {
            day += arr[i];
        }
        
        day += b;
        answer = s[(day % 7)];
        
        return answer;
    }
}