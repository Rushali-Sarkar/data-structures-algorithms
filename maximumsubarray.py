def maximumCrossSubarray(arr: [int], low: int, mid: int, high: int) -> (int):

    max_left_sum = float('inf') * -1
    entire_sum = 0
    left_index = -1
    for i in range(mid, low - 1, -1):
        entire_sum += arr[i]
        if entire_sum > max_left_sum:
            max_left_sum = entire_sum
            left_index = i

    max_right_sum = float('inf') * -1
    entire_sum = 0
    right_index = -1
    for i in range(mid + 1, high + 1, 1):
        entire_sum += arr[i]
        if entire_sum > max_right_sum:
            max_right_sum = entire_sum
            right_index = i

    return right_index, left_index, max_left_sum + max_right_sum


def maximumSubarray(arr: [int], low: int, high: int) -> (int):

    if high == low:
        return high, low, arr[low]
    
    mid = (high + low) // 2
    left_high, left_low, left_sum = maximumSubarray(arr, low, mid)
    right_high, right_low, right_sum = maximumSubarray(arr, mid + 1, high)
    cross_high, cross_low, cross_sum = maximumCrossSubarray(arr, low, mid, high)

    if cross_sum >= left_sum and cross_sum >= right_sum:
        return cross_high, cross_low, cross_sum
    if right_sum >= left_sum:
        return right_high, right_low, right_sum
    return left_high, left_low, left_sum


if __name__ == "__main__":

    arr1 = [1, 2, -1, 4, 3, 8, -6, 5, 11, 21]
    arr2 = [7, 6, 5, 0, -34, 5, 6, 7, 8, 9, 11]
    arr3 = [1, 4, 5, 7, -9, -6, -8, 21, 5, 4]
    arr4 = [-5, 20, 7, 0, -5, -6, -7, 8, 9]

    print(maximumSubarray(arr1, 0, len(arr1) - 1))
    print(maximumSubarray(arr2, 0, len(arr2) - 1))
    print(maximumSubarray(arr3, 0, len(arr3) - 1))
    print(maximumSubarray(arr4, 0, len(arr4) - 1))
