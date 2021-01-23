def twonumbersum(arr: [int], summation: int) -> [int]:

    arr.sort()

    left = 0;
    right = len(arr) - 1;

    while (left < right):

        expected_sum = arr[left] + arr[right]

        if expected_sum  == summation:
            return [arr[left], arr[right]]

        if expected_sum < summation:
            left = left + 1

        if expected_sum > summation:
            right = right - 1

    return [-1, -1]


if __name__ == "__main__":

    arr = [-4, -1, 1, 3, 5, 6, 8, 11]
    summation = 10

    number1, number2 = twonumbersum(arr, summation)
    print("[", number1, ", ", number2, "]")

