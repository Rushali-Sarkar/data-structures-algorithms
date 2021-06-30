def rotateMatrix(matrix: [[int]]) -> [[int]]:
    new_matrix = []
    rows = len(matrix)
    columns = len(matrix[0])
    for i in range(columns - 1, -1, -1):
        current_row = []
        for j in range(rows):
            current_row.append(matrix[j][i])
        new_matrix.append(current_row)
    return new_matrix

def printMatrix(matrix: [[int]]) -> None:
    rows = len(matrix)
    columns = len(matrix[0])
    for i in range(rows):
        for j in range(columns):
            print(matrix[i][j], end = "\t")
        print()
    return None

matrix = [["A", "B"], ["C", "D"]]
for i in range(4):
    matrix = rotateMatrix(matrix)
    printMatrix(matrix)
    print()
