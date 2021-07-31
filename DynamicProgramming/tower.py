def tower(discs: int) -> None:

    source = [i + 1 for i in range(discs)]
    extra = []
    destination = []

    move_from = ""
    move_to = ""
    disc_to_move = 0

    is_even = discs % 2 == 0

    for i in range(1, 2 ** discs):

        first_condition = i % 3 == 1
        second_condition = i % 3 == 2
        if not is_even:
            first_condition, second_condition = second_condition, first_condition

        if first_condition:

            is_both_not_empty = len(source) != 0 and len(extra) != 0 

            if len(extra) == 0 or (is_both_not_empty and extra[-1] <  source[-1]):

                move_from = "Source"
                move_to = "Extra"
                disc_to_move = source[-1]
                source.pop()
                extra.append(disc_to_move)

            elif len(source) == 0 or(is_both_not_empty and source[-1] < extra[-1]):

                move_from = "Extra"
                move_to = "Source"
                disc_to_move = extra[-1]
                extra.pop()
                source.append(disc_to_move)


        elif second_condition:

            is_both_not_empty = len(source) != 0 and len(destination) != 0

            if len(destination) == 0 or (is_both_not_empty and destination[-1] < source[-1]):

                move_from = "Source"
                move_to = "Destination"
                disc_to_move = source[-1]
                source.pop()
                destination.append(disc_to_move)

            elif len(source) == 0 or (is_both_not_empty and source[-1] < destination[-1]):

                move_from = "Destination"
                move_to = "Source"
                disc_to_move = destination[-1]
                destination.pop()
                source.append(disc_to_move)


        elif i % 3 == 0:

            is_both_not_empty = len(extra) != 0 and len(destination) != 0

            if len(destination) == 0 or (is_both_not_empty and extra[-1] > destination[-1]):

                move_from = "Extra"
                move_to = "Destination"
                disc_to_move = extra[-1]
                extra.pop()
                destination.append(disc_to_move)

            elif len(extra) == 0 or (is_both_not_empty and destination[-1] > extra[-1]):

                move_from = "Destination"
                move_to = "Extra"
                disc_to_move = destination[-1]
                destination.pop()
                extra.append(disc_to_move)


        print("Moving Disc", disc_to_move, "from", move_from, "to", move_to)


    return

n = int(input())
tower(n)
