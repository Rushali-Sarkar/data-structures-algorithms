def binaryAdd(binary1: [int], binary2: [int]) -> [int]:

        result = []
        pointer1 = len(binary1) - 1
        pointer2 = len(binary2) - 1
        sum_value = 0
        carry_value = 0

        while pointer1 >= 0 and pointer2 >= 0:

                digit1 = binary1[pointer1]
                digit2 = binary2[pointer2]

                if digit1 == 1 and digit2 == 1:
                        sum_value = 1 if carry_value == 1 else 0
                        carry_value = 1
                elif digit1 == 0 and digit2 == 0:
                        sum_value = 1 if carry_value == 1 else 0
                        carry_value = 0
                elif (digit1 == 0 and digit2 == 1) or (digit1 == 1 and digit2 == 0):
                        sum_value = 0 if carry_value == 1 else 1
                        carry_value = 1 if carry_value == 1 else 0

                result.append(sum_value)
                pointer1 -= 1
                pointer2 -= 1
        if carry_value == 1:
                result.append(carry_value)
        return result[::-1]


if __name__ == "__main__":

        binary1 = [1, 0, 1, 1, 0, 0, 1, 0]
        binary2 = [0, 1, 1, 0, 0, 1, 1, 0]

        print (binaryAdd (binary1, binary2)) 
         
