
def kEmptySlots(flowers: [int], k: int) -> int:
    next_day_index = {}
    for index, each in enumerate(flowers):
        next_day_index[each] = index
    
    day_start = 1
    indexes_bloomed_till_now = set([])

    def isNoBloomsInBetween(start: int, end: int) -> bool:
        nonlocal indexes_bloomed_till_now
        for i in range(start + 1, end):
            if i in isNoBloomsInBetween:
                return False 
        return True

    while day_start != len(flowers):

        current_index_to_bloom = next_day_index[day_start]
        possible_previous_index = current_index_to_bloom - k - 1
        possible_next_index = current_index_to_bloom + k + 1 
        if possible_previous_index >= 0 and possible_previous_index in indexes_bloomed_till_now and isNoBloomsInBetween(possible_previous_index, current_index_to_bloom):
            return day_start  
        if possible_next_index < len(flowers) and possible_next_index in indexes_bloomed_till_now and isNoBloomsInBetween(current_index_to_bloom, possible_next_index):
            return day_start 
        day_start += 1
        indexes_bloomed_till_now.add(current_index_to_bloom)
    return -1 


if __name__ == "__main__":
    x = list(map(int, input().split(" ")))
    k = int(input())
    print (kEmptySlots(x, k))

    
