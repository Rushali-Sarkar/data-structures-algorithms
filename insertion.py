def reverseInsertionSort (arr: [int]) -> [int]:
        for i in range(1, len(arr)):
                key = arr[i]
                j = i - 1
                while j >= 0 and arr[j] < key:
                        arr[j + 1] = arr[j]
                        j -= 1
                arr[j + 1] = key
        return arr

if __name__ == "__main__":

        arr = [1, 4, 5, 23, 45, 45, 67, 10, 9, 10, 33, 68, 95, 23, 58, 99, 25, 25, 75, 76]
        arr = reverseInsertionSort(arr)
        print (*arr)
