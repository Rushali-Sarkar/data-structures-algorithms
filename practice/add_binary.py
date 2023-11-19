def addBinaryDigits(digit1: int, digit2: int, carry: int) -> (int):
    add = 0
    if digit1 == 0 and digit2 == 0:
        add = 0 if carry == 0 else 1
        carry = 0
    elif digit1 == 0 and digit2 == 1 or digit1 == 1 and digit2 == 0:
        add = 1 if carry == 0 else 0
        carry = 0 if carry == 0 else 1
    elif digit1 == 1 and digit2 == 1:
        add = 0 if carry == 0 else 1
        carry = 1
    return add, carry

def binaryAddition(number1: [int], number2: [int]) -> [int]:

    index1 = len(number1) - 1
    index2 = len(number2) - 1
    result = []
    add = 0
    carry = 0

    while index1 >= 0 and index2 >= 0:
        add, carry = addBinaryDigits(number1[index1], number2[index2], carry)
        result.append(add)
        index1 -= 1
        index2 -= 1
    
    while index1 >= 0:
        add, carry = addBinaryDigits(number1[index1], 0, carry)
        result.append(add)
        index1 -= 1

    while index2 >= 0:
        add, carry = addBinaryDigits(0, number2[index2], carry)
        result.append(add)
        index2 -= 1

    if carry != 0:
        result.append(carry)

    return result[::-1]


print("11 + 11", end = " = ")
print(binaryAddition([1, 1], [1, 1]))
print("110 + 101", end = " = ")
print(binaryAddition([1, 1, 0], [1, 0, 1]))
print("11 + 101", end = " = ")
print(binaryAddition([1, 1], [1, 0, 1]))
