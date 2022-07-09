def kadens(arr: [int]) -> int:

    current_sum = float('inf') * -1
    max_sum = float('inf') * -1
    current_start = -1
    current_end = -1
    max_start = -1
    max_end = -1

    for i in range(len(arr)):
        
        if arr[i] > current_sum + arr[i]:
            current_start = i
            current_end = i
            current_sum = arr[i]
        else:
            current_end = i
            current_sum += arr[i]
        if current_sum > max_sum:
            max_start = current_start
            max_end = current_end
            max_sum = current_sum
    
    return max_start, max_end, max_sum


if __name__ == "__main__":

    arr = [-1, 5, 6, 7, 0, -3, -4, 2, -3, -7, 8]
    print(kadens(arr))

