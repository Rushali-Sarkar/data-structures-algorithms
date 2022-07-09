def mergeSortedArrays(array1: int, array2: int) -> [int]:

        array =[]
        pointer1 = 0
        pointer2 = 0
        end1 = len(array1)
        end2 = len(array2)

        while pointer1 < end1 and pointer2 < end2:

                number1 = array1[pointer1]
                number2 = array2[pointer2]
                if number1 <= number2:
                        array.append(number1)
                        pointer1 += 1
                else:
                        array.append(number2)
                        pointer2 += 1

        while pointer1 < end1:
                array.append(array1[pointer1])
                pointer1 += 1
        while pointer2 < end2:
                array.append(array2[pointer2])
                pointer2 += 1

        return array


def mergeSort(array: [int]) -> [int]:
        
        if len(array) == 1:
                return array
        middle_index = len(array) // 2
        left_half = mergeSort(array[:middle_index])
        right_half = mergeSort(array[middle_index:])
        return mergeSortedArrays(left_half, right_half)


if __name__ == "__main__":

        arr = [9, 2, 4, 67, 67, 2, 1, 3, 4, 9, 70, 100, 45, 68, 23, 45, 21, -8, 45, -9, -90, 103]
        print(mergeSort(arr))
