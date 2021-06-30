def ispower(x: int) -> bool:

    if x < 3:
        return False

    while x > 1:
        if x % 3 != 0:
            return False
        x = x / 3

    return True


if __name__ == "__main__":

    x = int(input())
    print(ispower(x))
