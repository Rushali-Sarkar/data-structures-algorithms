def validatesubsequence(sequence: [int], subsequence: [int]) -> bool:

    sequence_index = 0;
    subsequence_index = 0;

    while sequence_index < len(sequence) and subsequence_index < len(subsequence):

        if (sequence[sequence_index] == subsequence[subsequence_index]):
            subsequence_index += 1

        sequence_index += 1

    return subsequence_index == len(subsequence)


if __name__ == "__main__":

    sequence = [5, 1, 22, 25, 6, -1, 8, 10]
    subsequence = [1, 6, -1, 10]

    print(validatesubsequence(sequence, subsequence))
