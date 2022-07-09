def matrixAddition(arr1: [[int]], arr2: [[int]]) -> [[int]]:
    for i in range(len(arr1)):
        for j in range(len(arr1[0])):
            arr1[i][j] += arr2[i][j]
    return arr1

def matrixCombination(s1: [[int]], s2: [[int]], s3: [[int]], s4: [[int]]) -> [[int]]:
    return [s1[i] + s2[i] for i in range(len(s1))] + [s3[i] + s4[i] for i in range(len(s3))]

def matrixMultiplication(arr1: [[int]], arr2: [[int]], n: int) -> [[int]]:

    if n == 1:
        return [[arr1[0][0] * arr2[0][0]]]
    n = n // 2
    s1 = matrixAddition(matrixMultiplication(), matrixMultiplication())
