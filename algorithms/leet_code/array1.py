def runningsum(nums: [int]) -> [int]:
    for i in range(1, len(nums)):
        nums[i] += nums[i - 1]
    return nums

nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(runningsum(nums))