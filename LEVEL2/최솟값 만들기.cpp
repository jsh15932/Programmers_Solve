#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    for(int i = 0; i < A.size(); i++) {
        int res = A[i] * B[i];
        answer += res;
    }
    
    return answer;
}