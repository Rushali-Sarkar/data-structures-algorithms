def insertionSort(arr: [int]) -> [int]:

    for i in range(1, len(arr)):
        current_element = arr[i]
        start_index = i - 1
        while start_index >= 0 and arr[start_index] > current_element:
            arr[start_index + 1] = arr[start_index]
            start_index -= 1
        arr[start_index + 1] = current_element
    return arr


print(insertionSort([1, 4, 6, 1, 1, 1, 2, 90, 32, 87, 1, 4, 7, 0]))
