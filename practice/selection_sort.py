def selectionSort(arr: [int]) -> [int]:

    for i in range(len(arr) - 1):
        minimum_number_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[minimum_number_index]:
                minimum_number_index = j
        arr[i], arr[minimum_number_index] = arr[minimum_number_index], arr[i]
    return arr


print(selectionSort([2, 4, 5, 1, 1, 2, 4, 9, 0, 2, 3, 1, 5, 6, 7, 8, 9, 2, 1]))
