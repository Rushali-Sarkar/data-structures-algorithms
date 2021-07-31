def graycode(n: int) -> [int]:
    return [i ^ (i >> 1) for i in range(2 ** n)]


if __name__ == "__main__":
    n = int(input())
    print(graycode(n))
