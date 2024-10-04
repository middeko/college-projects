"""
File: file_system.py
Name: Wilfried Dim
Date: 12/1/2022
Section: 32
Email: wtendjo1@umbc.edu
Description:
"""


def run_the_file_system(shell):
    """
    :param shell: the empty dictionary imported
    :return: none * runs until "exit" is entered by user *
    """
    file_system = shell
    # starting root directory
    file_system["root"] = {"files_key": []}
    current_directory = "root"
    path = ["root"]
    flag = True
    while flag:
        user_input = input("[cmsc201 proj3]$ ")
        user_input_list = user_input.split()

        # pwd
        if user_input_list[0] == "pwd":
            print(pwd(path))

        # ls
        elif user_input_list[0] == "ls":
            if user_input_list[0] == True:
                print(ls(current_directory, user_input_list[1], file_system))
            else:
                print(ls(current_directory, "", file_system))

        # mkdir
        elif user_input_list[0] == "mkdir":
            mkdir(current_directory, user_input_list[1], file_system)
            print(file_system)

        # cd
        elif user_input_list[0] == "cd":
            cwd = cd(user_input_list[1], file_system)
            if cwd == "root":
                current_directory = "root"
                path = ["root"]
            elif cwd == current_directory:
                print("This is the current directory")
            elif cwd == None:
                print("error")
            else:
                current_directory = cwd
                path.append(current_directory)
                print(current_directory)
                print(path)

        # touch
        elif user_input_list[0] == "touch":
            touch(current_directory, user_input_list[1], file_system)
            print(file_system)

        # rm
        elif user_input_list[0] == "rm":
            rm(current_directory, user_input_list[1], file_system)
            print(file_system)

        # locate
        elif user_input_list[0] == "locate":
            locate(current_directory, user_input_list[1], file_system)

        # exit command
        elif user_input == "exit":
            flag = False
        else:
            print(user_input_list[0] + ": Command not found")


def pwd(path):
    """
    :param path: the current path list
    :return: a string of the current directory path
    """
    current = ""
    # adds each step in "path list" to an empty string in order to display
    for element in path:
        current += ("/" + element)
    return current


def ls(current_directory, directory_name, file_system):
    """
    :param current_directory: the current directory the user is in
    :param file_system: the shell
    :return: a print statement of the files and directories in the current
    directory
    """
    # if there is no path specified
    if bool(directory_name) == False:
        for key, value in file_system.items():
            if key == current_directory:
                for element in value:
                    print(type(element))
                    if element == list:
                        for file in element:
                            print(file)
                    else:
                        print(element)
            else:
                return ls(current_directory, directory_name, value)
        return
    # if there is a path specified
    else:
        ""


def mkdir(current_directory, directory_name, file_system):
    """
    :param current_directory: the current directory the user is in
    :param directory_name: the directory name the user inputs
    :param file_system: the shell
    :return: a new directory inside the current directory
    """

    for key, value in file_system.items():
        # if the key is the same as the current directory
        # a new directory will be made inside the current directory
        if key == current_directory:
            file_system[directory_name] = {"files_key": []}
            return file_system
        else:
            # recursive call if no key in "file_system.items" == key
            return mkdir(current_directory, directory_name, value)


def cd(directory_name, file_system):
    """
    :param directory_name: the directory name the user inputs
    :param file_system: the shell
    :return: a string of the current directory
    """
    # if the user inputs slash the current directory returns the start
    if directory_name == "/":
        return "root"
    else:
        # if the value of a key is a dictionary, if the key == the desired
        # directory, it will return the key as the current directory
        for key, value in file_system.items():
            if type(value) == dict:
                if key == directory_name:
                    return key
            else:
                return cd(directory_name, value)


def touch(current_directory, file_name, file_system):
    """
    :param current_directory: the current directory the user is in
    :param file_name: the file name the user inputs
    :param file_system: the shell
    :return: the file system with the new file inside
    """
    # if the element is not found in the "files_key" list, it will
    # append the value to the list
    for key, value in file_system.items():
        if key == current_directory:
            for element in file_system[current_directory]["files_key"]:
                if element == file_name:
                    print("This file already exists")
                    return file_system
            value["files_key"].append(file_name)
            return file_system
        else:
            return mkdir(current_directory, file_name, value)


def rm(current_directory, file_name, file_system):
    """
    :param current_directory: the current directory the user is in
    :param file_name: the file name the user inputs
    :param file_system: the shell
    :return: the file system with the specified file removed
    """
    for key, value in file_system.items():
        if key == current_directory:
            if value not in file_system[current_directory]["files_key"]:
                    print()
                    return file_system
            file_system["files_key"].remove(file_name)
            return file_system
        else:
            return mkdir(current_directory, file_name, value)


def locate(current_directory, file_name, file_system):
    """
    :param current_directory: the current directory the user is in
    :param file_name: the file name the user inputs
    :param file_system: the shell
    :return: a print statement stating where the file is located
    """
    # if the desired directory is not found it will call the function
    # recursively with the value as the new dictionary
    for key, value in file_system.items():
        for i in range(len(value)):
            if key == current_directory:
                for value_2 in value:
                    if type(value_2) == list:
                        for element in value_2:
                            if element == file_name:
                                print("A file with that name was found "
                                      "at the following path:")
                                print(current_directory, value_2, element)
        else:
            return locate(current_directory, file_name, key)


if __name__ == "__main__":
    empty_shell = {}
    run_the_file_system(empty_shell)
