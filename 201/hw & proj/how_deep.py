import random


def how_deep(list_struct):
    if not list_struct:
        # base case if an empty list is returned
        return 1
    else:
        # checks the depth of each sublist and if the new one is deeper
        # it replaces the old max value
        max_depth = 0
        for sublist in list_struct:
            depth = how_deep(sublist)
            if depth > max_depth:
                max_depth = depth
        return max_depth + 1


def make_list_structure(max_depth, p=.8):
    if max_depth and random.random() < p:
        new_list = []
        for i in range(5):
            sub_list = make_list_structure(max_depth - 1, p * .9)
            if sub_list is not None:
                new_list.append(sub_list)
        return new_list

    return None


if __name__ == '__main__':
    print(how_deep([[[], [], [], [[[]]]], []]))
    print(how_deep([]))
    print(how_deep([[], []]))
    print(how_deep([[[]], [], [[]], [[[]]]]))
    print(how_deep([[[[], [[]], [[[]]], [[[[]]]]]]]))
    print(how_deep([[[], []], [], [[], []]]))
