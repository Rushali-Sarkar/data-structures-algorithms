def canSegment(dictionary: set([]), string: str) -> bool:
    
    if len(string) == 0:
        return True

    isPossible = [False]
    for limit in range(len(string) + 1):
        if string[:limit] in dictionary:
            isPossible.append(canSegment(dictionary, string[limit:]))
    return any(isPossible)
    


if __name__ == "__main__":

    n = int(input())
    dictionary = set([])
    for i in range(n):
        dictionary.add(input())
    string = input()
    print(canSegment(dictionary, string))
        
            
