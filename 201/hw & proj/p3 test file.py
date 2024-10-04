def mkdir(current_directory, directory_name, file_system):
    if directory_name in file_system:
        print("Directory already exists.")
    else:
        file_system[current_directory][directory_name] = {directory_name: {}}
        return file_system