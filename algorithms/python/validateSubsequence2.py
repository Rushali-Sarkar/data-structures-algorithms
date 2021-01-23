def validatesubsequence(sequence: int, subsequence: int) -> bool:

    subsequence_index = 0

    for each in sequence:

        if (each == subsequence[subsequence_index]):
            subsequence_index += 1

        if (subsequence_index == len(subsequence)):
            return True

    return False


if __name__ == "__main__":

    sequence = [5, 1, 22, 25, 6, -1, 8, 10]
    subsequence = [1, 6, -1, 10]

    print(validatesubsequence(sequence, subsequence))

