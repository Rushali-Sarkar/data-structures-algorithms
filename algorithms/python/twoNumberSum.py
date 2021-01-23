def twonumbersum(arr: [int], summation: int) -> [int]:

    trackPossibleSum = {};

    for each in arr:

        possible_match = summation - each

        if possible_match in trackPossibleSum:
            return [possible_match, each]

        trackPossibleSum[each] = True

    return [-1, -1]


if __name__ == "__main__":

    arr = [3, 5, -4, 8, 11, 1, -1, 6]
    summation = 10

    number1, number2 = twonumbersum(arr, summation)
    print("[", number1, ", ", number2, "]")




