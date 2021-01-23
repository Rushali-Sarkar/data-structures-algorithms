def fibonacci_helper(n: int, fibonacci_table: {int, int}) -> (int, {int, int}):

    if n in fibonacci_table:
        return fibonacci_table[n]

    fibonacci_table[n] = fibonacci_helper(n - 1, fibonacci_table) + \
                         fibonacci_helper(n - 2, fibonacci_table)

    return fibonacci_table[n]


def nthfibonacci(n: int) -> int:

    fibonacci_table = {}
    fibonacci_table[1] = 0
    fibonacci_table[2] = 1
    return fibonacci_helper(n, fibonacci_table)

if __name__ == "__main__":

    print(nthfibonacci(6))
    print(nthfibonacci(5))
    print(nthfibonacci(4))
    print(nthfibonacci(3))
    print(nthfibonacci(2))
    print(nthfibonacci(1))
