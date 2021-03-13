def twonumbersum(arr: [int], summation: int) -> [int]:

    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):

            if arr[i] + arr[j] == summation:
                return [arr[i], arr[j]]

    return [-1, -1]


if __name__ == "__main__":

    arr = [-4, -1, 1, 3, 5, 6, 8, 11]
    summation = 10

    number1, number2 = twonumbersum(arr, summation)
    print("[", number1, ", ", number2, "]")
