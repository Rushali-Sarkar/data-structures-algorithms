def mergeintervals(intervals: [[int]]) -> [[int]]:
    stack = [intervals[0]]
    for i in range(1, len(intervals)):
        previous_interval = stack[-1]
        current_interval = intervals[i]
        previous_start, previous_end = previous_interval
        current_start, current_end = current_interval
        if previous_end >= current_start:
            stack.pop()
            stack.append([previous_start, current_end])
        else:
            stack.append(current_interval)
    return stack
    
if __name__ == "__main__":
    
    n = int(input())
    intervals = []
    for i in range(n):
        current_interval = list(map(int, input().split()))
        intervals.append(current_interval)
        
    mergedIntervals = mergeintervals(intervals)
    for interval in mergedIntervals:
        print(*interval)
