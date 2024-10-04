def ls(current_directory, file_system):
    directories = file_system.get(current_directory)
    print("Contents for", current_directory)
    for key in directories:
        print(key)


def cd(directory_name, file_system):
    print(file_system)
    print(list(file_system.keys()))
    print(list(file_system.values()))
    if directory_name == "home":
        key_list = (list(file_system.keys()))
        if directory_name not in key_list:
            print("Directory does not exist")
        else:
            return directory_name
    else:
        key_list = (list(file_system.values()))
        for dictionary in key_list:
            print(dictionary)
            for key in dictionary:
                if key == directory_name:
                    return directory_name
                else:
                    print("Directory does not exist")


def mkdir(current_directory, directory_name, file_system):
    if directory_name in file_system:
        print("Directory already exists.")
    else:
        file_system[current_directory][directory_name] = {}
        return file_system


def touch(current_directory, file_name, file_system):
    file_system[current_directory].append(file_name)
    return file_system

def main():
    file_system = {}
    file_system["home"] = {"test": "1"}
    current_directory = cd("home", file_system)
    flag = True
    while flag:
        user_input = input("[cmsc201 proj3]$ ")
        user_input_list = user_input.split()
        if user_input_list[0] == "ls":
            print(ls(current_directory, file_system))

        elif user_input_list[0] == "cd":
            current_directory = cd(user_input_list, file_system)

        elif user_input_list[0] == "mkdir":
            mkdir(current_directory, user_input_list[1], file_system)
            # touch
        elif user_input_list[0] == "touch":
            touch(current_directory, user_input_list[1], file_system)
            print(file_system)



main()
