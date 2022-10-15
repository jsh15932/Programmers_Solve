def solution(sticker):
    answer = 0

    if len(sticker) <= 3:
        res = 0
        for i in range(0, len(sticker)):
            res = max(res, sticker[i])
        return res
    
    arr1 = [0] * len(sticker)
    arr2 = [0] * len(sticker)
    arr1[0] = sticker[0]
    arr1[1] = sticker[0]
    arr2[0] = 0
    arr2[1] = sticker[1]

    for i in range(2, len(sticker) - 1):
        arr1[i] = max(arr1[i - 1], arr1[i - 2] + sticker[i])
        arr2[i] = max(arr2[i - 1], arr2[i - 2] + sticker[i])

    res1 = max(arr1[len(sticker) - 2], arr1[len(sticker) - 3])
    res2 = max(arr2[len(sticker) - 2], arr2[len(sticker) - 3] + sticker[len(sticker) - 1])

    answer = max(res1, res2)

    return answer