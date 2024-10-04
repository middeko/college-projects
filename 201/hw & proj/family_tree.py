"""
File: family_tree.py
Name: Wilfried Dim
Date: 05/12/2023
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will allow the user to create, save, and load
family trees
"""


def change_family(tree):
    family_tree = tree
    user_input_log = []
    flag = True
    while flag:
        # gets the input from user and runs the appropriate function
        user_input = input(">>> ")
        user_input = user_input.replace("-", " ")
        user_input_list = user_input.split()
        # save
        if user_input_list[0] == "save":
            file = open(user_input_list[1], "w")
            for i in range(len(user_input_log)):
                file.write(user_input_log[i] + "\n")
            file.close()
        # load
        elif user_input_list[0] == "load":
            # clears user log
            user_input_log = []
            file = open(user_input_list[1], "r")
            lines = file.readlines()
            new_tree = load(lines, user_input_log)
            family_tree = new_tree
            print("The file has been loaded")
        # create
        elif user_input_list[0] == "create":
            new_tree = create(family_tree, user_input_list[1])
            family_tree = new_tree
            # after create and set functions run, the command is saved to log
            # to be used by save function after
            user_input_log.append(user_input)
            print(user_input_list[1], "has been created")
        # set mother
        elif user_input_list[0] == "set" and user_input_list[1] == "mother":
            new_tree = set_mother(family_tree, user_input_list[2],
                                  user_input_list[3])
            family_tree = new_tree
            user_input_log.append(user_input)
        # set father
        elif user_input_list[0] == "set" and user_input_list[1] == "father":
            new_tree = set_father(family_tree, user_input_list[2],
                                  user_input_list[3])
            family_tree = new_tree
            user_input_log.append(user_input)
        # is ancestor
        elif user_input_list[0] == "is" and user_input_list[1] == "ancestor":
            mother = is_ancestor(family_tree, user_input_list[2],
                                 user_input_list[3], "Mother")
            father = is_ancestor(family_tree, user_input_list[2],
                                 user_input_list[3], "Father")
            if mother or father == True:
                print(user_input_list[3], "is an ancestor of",
                      user_input_list[2])
            else:
                print(user_input_list[3], "is not an ancestor of",
                      user_input_list[2])
        # is descendant
        elif user_input_list[0] == "is" and user_input_list[1] == "descendant":
            check = 0
            for i in range(len(family_tree[user_input_list[3]]["Children"])):
                child = is_descendant(family_tree, user_input_list[2],
                                      family_tree[user_input_list[3]]
                                      ["Children"][i], i)
                if child == True:
                    check += 1
            if check >= 1:
                print(user_input_list[2], "is a descendant of",
                      user_input_list[3])
            else:
                print(user_input_list[2], "is NOT a descendant of",
                      user_input_list[3])
        # display person
        elif user_input_list[0] == "display" and user_input_list[
            1] == "person":
            display_person(family_tree, user_input_list[2])
        # display people
        elif user_input_list[0] == "display" and user_input_list[
            1] == "people":
            display_people(family_tree)
        else:
            print("invalid input")


def load(lines, user_input_log):
    # resets dictionary
    family_tree = {}
    # runs the commands found in the file and re-creates the family tree
    for i in range(len(lines)):
        user_input = lines[i]
        user_input = user_input.replace("-", " ")
        user_input_list = user_input.split()
        # create
        if user_input_list[0] == "create":
            new_tree = create(family_tree, user_input_list[1])
            family_tree = new_tree
            user_input_log.append(user_input)
        # set mother
        elif user_input_list[0] == "set" and user_input_list[1] == "mother":
            new_tree = set_mother(family_tree, user_input_list[2],
                                  user_input_list[3])
            family_tree = new_tree
            user_input_log.append(user_input)
        # set father
        elif user_input_list[0] == "set" and user_input_list[1] == "father":
            new_tree = set_father(family_tree, user_input_list[2],
                                  user_input_list[3])
            family_tree = new_tree
            user_input_log.append(user_input)
    return family_tree


def create(tree, person):
    # checks if person already exists
    duplication_check = 0
    for key in tree:
        if key == person:
            duplication_check += 1
    if duplication_check != 0:
        print("person already exists")
        return tree
    else:
        # creates person
        tree[person] = {"Mother": "", "Father": "", "Children": []}
    return tree


def set_mother(tree, person, mother):
    # checks to make sure mother is empty
    for key, value in tree[person].items():
        if key == "Mother":
            if value != "":
                print("mother already exists")
                return tree
    # if mother is empty
    tree[person]["Mother"] = mother
    tree[mother]["Children"].append(person)
    return tree


def set_father(tree, person, dad):
    # checks to make sure father is empty
    for key, value in tree[person].items():
        if key == "Father":
            if value != "":
                print("Father already exists")
                return tree
    # if father is empty
    tree[person]["Father"] = dad
    tree[dad]["Children"].append(person)
    return tree


def is_ancestor(tree, ancestor, person, parent):
    # if no parent exists, it returns false
    if tree[person][parent] == "":
        return False
    else:
        # if parent matches desired ancestor, returns true
        if tree[person][parent] == ancestor:
            return True
        # recursively calls function with the parent's parent
        else:
            return is_ancestor(tree, ancestor, tree[person][parent], parent)


def is_descendant(tree, descendant, person, child_number):
    # if no child exists, it returns false
    if tree[person]["Children"][number] == "":
        return False
    else:
        # if child matches desired descendant, returns true
        if tree[person]["Children"][child_number] == descendant:
            return True
        else:
            # recursively calls function with the child's child
            return is_descendant(tree, descendant, person, child_number + 1)


def display_person(tree, person):
    # prints out the specified person and their relatives
    print(person)
    for key, value in tree[person].items():
        if value == "" or value == []:
            print(key, ":", "None Listed")
        else:
            print(key, ":", value)


def display_people(tree):
    # prints out each person and their relatives
    for key in tree:
        print(key)
        for keys, value in tree[key].items():
            if value == "" or value == []:
                print("\t", keys, ":", "None Listed")
            else:
                print("\t", keys, ":", value)


if __name__ == "__main__":
    # runs program
    run_program = True
    while run_program:
        ancestor_tree = {}
        change_family(ancestor_tree)
