def towerofhanoi(source: str, extra: str, destination: str, disc: int) -> None:

    if disc <= 0:
        return;

    towerofhanoi(source, destination, extra, disc - 1)
    print("Moved Disc ", disc, " from ", source, " to", destination)
    towerofhanoi(extra, source, destination,  disc - 1)
    return;



towerofhanoi("Source", "Extra", "Destination", 4)
