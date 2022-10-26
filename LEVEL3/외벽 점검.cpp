#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    int size = weak.size();
    weak.resize(2 * weak.size());

    for(int i = size; i < weak.size(); i++) {
        weak[i] = weak[i - size] + n;
    }

    sort(dist.begin(), dist.end());

    do {
        for(int i = 0; i < size; i++) {
            int start = weak[i];
            int end = weak[i + size - 1];

            for(int j = 0; j < dist.size(); j++) {
                start += dist[j];
                
                if(start >= end) {
                    answer = min(answer, j + 1);
                    break;
                }

                int next = upper_bound(weak.begin(), weak.end(), start) - weak.begin();
                start = weak[next];
            }
        }   
    } while(next_permutation(dist.begin(), dist.end()));

    if(answer == 1e9) {
        return -1;
    }

    return answer;
}