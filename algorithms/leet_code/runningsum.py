def runningsum(nums: [int]) -> [int]:
    
    size = len(nums) 
    result = []
    
    for i in range(size):
        running_sum = 0
        for j in range(i + 1):
            running_sum += nums[j]
        result.append(running_sum)
        
    return result




        

    
    