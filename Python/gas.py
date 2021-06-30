def findStart(stations: int, gas: [int], cost: [int]) -> int:
    
    start = 0
    current_delta = 0
    total_delta = 0
    for i in range(stations):
        
        delta = gas[i] - cost[i]
        total_delta += delta
        current_delta += delta
        
        if current_delta < 0:
            current_delta = 0
            start = i + 1
            
    if total_delta < 0:
        return -1
        
    for i in range(start):
        current_delta += gas[i] - cost[i]
        
    if current_delta >= 0:
        return start
    return -1
        
        

if __name__ == "__main__":
    
    stations = int(input())
    gas = list(map(int, input().split()))
    cost = list(map(int, input().split()))
    print(findStart(stations, gas, cost))
    
