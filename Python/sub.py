def canSegment(dictionary: set([]), string: str) -> bool:
    
    if len(string) == 0:
        return True
        
    limit = 0
    while limit < len(string) and string[: limit] not in dictionary:
        limit += 1
    if string[: limit] in dictionary:
        return canSegment(dictionary, string[limit:]) or canSegment(dictionary, string[limit + 1:])
    return False
    
if __name__ == "__main__":
    
    n = int(input())
    dictionary = set([])
    for i in range(n):
        dictionary.add(input())
    string = input()
    print(canSegment(dictionary, string))
