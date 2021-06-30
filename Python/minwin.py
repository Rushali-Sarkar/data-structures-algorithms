def findSubstring(parent_string: str, target_string: str) -> str:
    
    left = 0
    right = 0
    current_substr = ""
    index = 0
    
    while right < len(parent_string):
        
        current_comparison = parent_string[right]
        to_find = target_string[index]
        substring = parent_string[left: right]
        
        if current_comparison == to_find:
            right += 1
            index += 1
            
        if len(substring) > len(current_substr):
            current_substr = substring
            
        if current_comparison != to_find:
            index = 0
            right += 1
            left = right
            
    return current_substr


if __name__ == "__main__":
    
    parent_string = input()
    target_string = input()
    
    biggest_substr =  findSubstring(parent_string, target_string)
    print(biggest_substr)
    
    
        
