def Divisors(num: int) -> [int]:
    
    sqrt = int(num ** (1 / 2)) + 1
    divisors = []
    for i in range(1, sqrt):
        if num % i == 0:
            if i == num / i:
                divisors.append(i)
            else:
                divisors.append(i)
                divisors.append(int(num / i))
    
    return divisors

print(Divisors(21))
print(Divisors(4))
print(Divisors(16))