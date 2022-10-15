#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    if(sticker.size() <= 3) {
        for(int i = 0; i < sticker.size(); i++) {
            answer = max(answer, sticker[i]);
        }
        return answer;
    }

    int arr1[sticker.size()], arr2[sticker.size()];

    arr1[0] = sticker[0];
    arr1[1] = sticker[0];
    arr2[2] = 0;
    arr2[1] = sticker[1];

    for(int i = 2; i < sticker.size() - 1; i++) {
        arr1[i] = max(arr1[i - 1], arr1[i - 2] + sticker[i]);
        arr2[i] = max(arr2[i - 1], arr2[i - 2] + sticker[i]);
    }

    int res1 = max(arr1[sticker.size() - 2], arr1[sticker.size() - 3]);
    int res2 = max(arr2[sticker.size() - 2], arr2[sticker.size() - 3] + sticker[sticker.size() - 1]);

    answer = max(res1, res2);

    return answer;
}