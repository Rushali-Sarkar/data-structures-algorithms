def nthfibonacci(n: int) -> int:

    if n == 1:
        return 0

    if n == 2:
        return 1

    return nthfibonacci(n - 1) + nthfibonacci(n - 2)


if __name__ == "__main__":

    print(nthfibonacci(6))
    print(nthfibonacci(5))
    print(nthfibonacci(4))
    print(nthfibonacci(3))
    print(nthfibonacci(2))
    print(nthfibonacci(1))
    
