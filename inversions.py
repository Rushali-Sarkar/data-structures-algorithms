def merge(left_count: int, arr1: [int], right_count: int, arr2: [int]) -> (int, [int]):
    
    inversion_count = 0
    right_smaller = 0
    pointer1 = 0
    pointer2 = 0
    end1 = len(arr1) - 1
    end2 = len(arr2) - 1

    result = []
    
    while pointer1 <= end1 and pointer2 <= end2:

        number1 = arr1[pointer1]
        number2 = arr2[pointer2]

        if number1 == number2:
            result.append(number1)
            result.append(number2)
            pointer1 += 1
            pointer2 += 1
        elif number1 < number2:
            inversion_count += right_smaller
            result.append(number1)
            pointer1 += 1
        elif number1 > number2:
            right_smaller += 1
            result.append(number2)
            pointer2 += 1

    while pointer1 <= end1:
        inversion_count += right_smaller
        number1 = arr1[pointer1]
        result.append(number1)
        pointer1 += 1

    while pointer2 <= end2:
        number2 = arr2[pointer2]
        result.append(number2)
        pointer2 += 1

    return (left_count + inversion_count + right_count, result)



def mergeSort(arr: [int]) -> (int, [int]):

    if len(arr) == 1:
        return (0, arr)

    middle_index = len(arr) // 2
    left_count, left_arr = mergeSort(arr[:middle_index])
    right_count, right_arr = mergeSort(arr[middle_index:])
    return merge(left_count, left_arr, right_count, right_arr)


if __name__ == "__main__":

    arr1 = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    arr2 = [2, 5, 7, 1, 6, 3, 0]

    print(mergeSort(arr1))
    print(mergeSort(arr2))





