#include<bits/stdc++.h>
using namespace std;

int arr1[100001], arr2[100001];

int solution(vector<int> sticker)
{
    int answer = 0;

    if(sticker.size() <= 3) {
        int res = 0;
        for(int i = 0; i < sticker.size(); i++) {
            res = max(res, sticker[i]);
        }
        return res;
    }

    arr1[0] = sticker[0];
    arr1[1] = sticker[0];
    arr2[0] = 0;
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