def linearSearch(arr: [int], element: int) -> [int]:
    indexes = []
    for index, each in enumerate(arr):
        if each == element:
            indexes.append(index)
    return indexes

print(linearSearch([5, 8, 1, 2, 0, 3, 4, 7, 8, 1, 4, 2, 8, 4, 1, 2], 2))
print(linearSearch([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], 22))
