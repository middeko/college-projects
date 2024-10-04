import random

PASSABLE = "_"
GOLD = "G"
BLOCKED = "*"
VISITED = 'V'


def create_map(seed, rows, cols):
    random.seed(seed)
    the_map = [
        [random.choices([PASSABLE, BLOCKED, GOLD], weights=[5, 2, 1])[0] for _
         in range(cols)] for _ in range(rows)]
    the_map[0][0] = PASSABLE
    for i in range(rows):
        for j in range(cols):
            if the_map[i][j] == GOLD:
                the_map[i][j] = GOLD + str(random.randint(1, 9))
    return the_map


def display_map(the_map):
    for row in the_map:
        for x in row:
            print(x.rjust(3), end='')
        print()


def count_the_gold(treasure_map, current_pos):
    row = current_pos[0]
    col = current_pos[1]

    # Check if we're out of bounds or if this position has already been visited
    if row < 0 or row >= len(treasure_map) or col < 0 or col >= len(
            treasure_map[0]) or treasure_map[row][col] == "*" or \
            treasure_map[row][col] == "V":
        return 0

    # Mark this position as visited
    treasure_map[row][col] = "V"

    # Check if there's gold at this position
    if treasure_map[row][col].startswith('G'):
        gold = int(treasure_map[row][col][1:])
    else:
        gold = 0

    # Recursively count gold in all four directions from the current position
    gold += count_the_gold(treasure_map, (row + 1, col))
    gold += count_the_gold(treasure_map, (row - 1, col))
    gold += count_the_gold(treasure_map, (row, col + 1))
    gold += count_the_gold(treasure_map, (row, col - 1))

    return gold


if __name__ == '__main__':
    my_map = create_map(*list(
        map(int, input('Enter seed rows cols separated by spaces: ').split())))
    display_map(my_map)
    print('Counting the gold...')
    value = count_the_gold(my_map, [0, 0])
    display_map(my_map)
    print('The total value of gold we can reach is: ', value)
