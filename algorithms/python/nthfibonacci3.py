def nthfibonacci(n: int) -> int:

    if n == 1:
        return 0

    if n == 2:
        return 1

    fibonacci_arr = [0, 1]
    for i in range(1, n - 1):
        summation = fibonacci_arr[0] + fibonacci_arr[1]
        fibonacci_arr[0] = fibonacci_arr[1]
        fibonacci_arr[1] = summation

    return fibonacci_arr[1]


if __name__ == "__main__":

    print(nthfibonacci(6))
    print(nthfibonacci(5))
    print(nthfibonacci(4))
    print(nthfibonacci(3))
    print(nthfibonacci(2))
    print(nthfibonacci(1))

