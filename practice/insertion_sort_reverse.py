def reverseInsertionSort(arr: [int]) -> [int]:

    for i in range(1, len(arr)):
        j = i - 1
        current_element = arr[i]
        while j >= 0 and arr[j] < current_element:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = current_element
    return arr

print(reverseInsertionSort([5, 0, 1, 2, 1, 1, 6, 7, 0, 8, 1, 5, 5, 3, 4, 5]))
