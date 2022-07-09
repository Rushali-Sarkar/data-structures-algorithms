def insertionsort (arr: [int]) -> [int]:
        for i in range (1, len(arr)):
                key = arr[i]
                j = i - 1
                while j >= 0 and arr[j] > key:
                        arr[j + 1] = arr[j]
                        j -= 1
                arr[j + 1] = key
        return arr


if __name__ == "__main__":

        arr = [1, 4, 6, 2, 3, 1, 1, 9, 10, 34, 21, 76, 87, 90, 90]
        arr = insertionsort (arr)
        print (arr)
