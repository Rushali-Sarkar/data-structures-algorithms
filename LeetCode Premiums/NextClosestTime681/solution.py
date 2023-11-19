def isTimeValid(time: str, digits: [str]) -> bool:
    return all([each in digits for each in time if each != ":"])

def convertTimeToString(time: (int)) -> str:
    hours, mins = time 
    new_hours, new_mins = "", ""
    if hours <= 9:
        new_hours = "0" + str(hours)
    else:
        new_hours = str(hours)
    if mins <= 9:
        new_mins = "0" + str(mins)
    else:
        new_mins = str(mins)
    return new_hours + ":" + new_mins

def getNextMinute(time: (int)) -> (int):
    hours, mins = time 
    if mins == 59:
        mins = 0
        if hours == 23:
            hours = 0
        else:
            hours += 1
    else:
        mins += 1
    
    return hours, mins

        


def nextClosestTime(current_time: str) -> str:
    current_time_digits = [each for each in current_time if each != ":"]
    hours, mins = int(current_time[:2]), int(current_time[3:])
    next_minute = getNextMinute((hours, mins))
    while not isTimeValid(convertTimeToString(next_minute), current_time_digits):
        next_minute = getNextMinute(next_minute)
    return convertTimeToString(next_minute)



if __name__ == "__main__":

    time = input()
    print(nextClosestTime(time))


    
