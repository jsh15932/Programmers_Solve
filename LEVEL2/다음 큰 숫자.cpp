#include<string>
#include<vector>
using namespace std;

int count(int n) {
    int res = 0;
    
    for(int i = 0; i < 31; i++) {
        if(n & 0x01 << i) {
            res++;
        }
    }
    
    return res;
}

int solution(int n) {
    int k = count(n);
    
    while(1) {
        n++;
        
        if(k == count(n)) {
            return n;
        }
    }
}