def pascletriangle(row: int) -> [int]:
    
    firstrow = [1]
    secondrow = [1, 1]
    
    if row == 1:
        return firstrow
    
    if row == 2:
        return secondrow
    
    count = 2
    previous = secondrow
    
    while count <= row:
        
        current = [1]
        for i in range(1, len(previous)):
            current.append(previous[i - 1] + previous[i])
        current.append(1)
        count += 1
        previous = current
        
    return previous


for i in range(1, 10):
    print(pascletriangle(i))

        
    
        