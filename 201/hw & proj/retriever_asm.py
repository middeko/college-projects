"""
File: retriever_asm.py
Author: Wilfried Dim
Date: 04/06/2023
Lab Section: 33
Email:  wtendjo1@umbc.edu
Description: This program will simulate a computer running a very simplified
assembly language
"""


def connect_to_data_file(filename):
    # opens the file and returns it to be used in main
    file = open(filename, "r")
    return file  # connection with the file


def move(destination, source):
    # will move the specified value to the desired destination
    if source[0] == "[":
        m_location = int(ram[int(source[1])])
        ram[int(destination[1])] = m_location
    else:
        ram[int(destination[1])] = int(source)


def math(operation, destination, input_1, input_2):
    # will change the value found in destination based on the operation
    # and values given
    if operation == "ADD":
        if input_1[0] == "[":
            location_1 = ram[int(input_1[1])]
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add location 1 and 2
                ram[int(destination[1])] = location_1 + location_2
            else:
                value = int(input_2)
                # add location and value
                ram[int(destination[1])] = location_1 + value
        else:
            value_1 = int(input_1)
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add value 1 and location 2
                ram[int(destination[1])] = value_1 + location_2
            else:
                value_2 = int(input_2)
                # add value 1 and value 2
                ram[int(destination[1])] = value_1 + value_2
    elif operation == "SUB":
        if input_1[0] == "[":
            location_1 = ram[int(input_1[1])]
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add location 1 and 2
                ram[int(destination[1])] = location_1 - location_2
            else:
                value = int(input_2)
                # add location and value
                ram[int(destination[1])] = location_1 - value
        else:
            value_1 = int(input_1)
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add value 1 and location 2
                ram[int(destination[1])] = value_1 - location_2
            else:
                value_2 = int(input_2)
                # add value 1 and value 2
                ram[int(destination[1])] = value_1 - value_2
    elif operation == "MUL":
        if input_1[0] == "[":
            location_1 = ram[int(input_1[1])]
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add location 1 and 2
                ram[int(destination[1])] = location_1 * location_2
            else:
                value = int(input_2)
                # add location and value
                ram[int(destination[1])] = location_1 * value
        else:
            value_1 = int(input_1)
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add value 1 and location 2
                ram[int(destination[1])] = value_1 * location_2
            else:
                value_2 = int(input_2)
                # add value 1 and value 2
                ram[int(destination[1])] = value_1 * value_2
    elif operation == "DIV":
        if input_1[0] == "[":
            location_1 = ram[int(input_1[1])]
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add location 1 and 2
                ram[int(destination[1])] = location_1 // location_2
            else:
                value = int(input_2)
                # add location and value
                ram[int(destination[1])] = location_1 // value
        else:
            value_1 = int(input_1)
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add value 1 and location 2
                ram[int(destination[1])] = value_1 // location_2
            else:
                value_2 = int(input_2)
                # add value 1 and value 2
                ram[int(destination[1])] = value_1 // value_2
    elif operation == "MOD":
        if input_1[0] == "[":
            location_1 = ram[int(input_1[1])]
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add location 1 and 2
                ram[int(destination[1])] = location_1 % location_2
            else:
                value = int(input_2)
                # add location and value
                ram[int(destination[1])] = location_1 % value
        else:
            value_1 = int(input_1)
            if input_2[0] == "[":
                location_2 = ram[int(input_2[1])]
                # add value 1 and location 2
                ram[int(destination[1])] = value_1 % location_2
            else:
                value_2 = int(input_2)
                # add value 1 and value 2
                ram[int(destination[1])] = value_1 % value_2


def compare(input_1, input_2):
    # returns the two numbers that will be compared in the conditional jump
    if input_1[0] == "[":
        location_1 = ram[int(input_1[1])]
        if input_2[0] == "[":
            location_2 = ram[int(input_2[1])]
            less_equal = [location_1, location_2]
            return less_equal
        else:
            value_2 = int(input_2)
            less_equal = [location_1, value_2]
            return less_equal
    else:
        value_1 = int(input_1)
        if input_2[0] == "[":
            location_2 = ram[int(input_2[1])]
            less_equal = [value_1, location_2]
            return less_equal
        else:
            value_2 = int(input_2)
            less_equal = [value_1, value_2]
            return less_equal


def cond_jump(flags, jump_type):
    # compares the two numbers from the compare function based
    # on the specified comparison
    if jump_type.upper() == "JE":
        if flags[0] == flags[1]:
            return "true"
        else:
            return "false"
    elif jump_type.upper() == "JNE":
        if flags[0] != flags[1]:
            return "true"
        else:
            return "false"
    elif jump_type.upper() == "JGE":
        if flags[0] >= flags[1]:
            return "true"
        else:
            return "false"
    elif jump_type.upper() == "JG":
        if flags[0] > flags[1]:
            return "true"
        else:
            return "false"
    elif jump_type.upper() == "JLE":
        if flags[0] <= flags[1]:
            return "true"
        else:
            return "false"
    elif jump_type.upper() == "JL":
        if flags[0] < flags[1]:
            return "true"
        else:
            return "false"


def interrupt(in_input, i_location):
    # sets the user's input as the value in the specified ram location
    ram[i_location] = in_input


if __name__ == "__main__":
    # initialization of all constants
    user_input = input("What file should we assemble, and what size "
                       "of ram should we use? ")
    user_input = user_input.split()
    infile = connect_to_data_file(user_input[0])
    ram_size = int(user_input[1])
    ram = []
    file_list = []
    comparison_flag = []
    line_count = 0
    for i in range(ram_size):
        ram.append(0)
    # running program
    # appends each line into a list as a list comprised of each word
    # / command of the line
    # if line is blank, it appends "NOP" to the list instead
    for line in infile:
        if line.strip() == "":
            file_list.append(["NOP"])
        else:
            line = line.split()
            file_list.append(line)
    # until hlt is called, the loop runs commands by using the line_count
    # that keeps track of which line to use in order to run a command
    flag = True
    while flag:
        # runs a command based on the first element of the nested list
        # if the first element is NOP, it will skip the line
        if file_list[line_count][0] == "NOP":
            line_count += 1
        elif file_list[line_count][0].upper() == "MOV":
            move(file_list[line_count][1], file_list[line_count][2])
            line_count += 1
        elif file_list[line_count][0].upper() == "ADD" or \
                file_list[line_count][0].upper() == "SUB" or \
                file_list[line_count][0].upper() == "MUL" or \
                file_list[line_count][0].upper() == "DIV" or \
                file_list[line_count][0].upper() == "MOD":
            math(file_list[line_count][0].upper(), file_list[line_count][1],
                 file_list[line_count][2], file_list[line_count][3])
            line_count += 1
        elif file_list[line_count][0].upper() == "JMP":
            line_count = int(file_list[line_count][1])
        elif file_list[line_count][0].upper() == "CMP":
            comparison_flag = compare(file_list[line_count][1],
                                      file_list[line_count][2])
            line_count += 1
        elif file_list[line_count][0][0].upper() == "J" and \
                file_list[line_count][0][1].upper() != "M":
            flag_test = cond_jump(comparison_flag, file_list[line_count][0])
            if flag_test == "true":
                line_count = int(file_list[line_count][1])
            else:
                line_count += 1
        elif file_list[line_count][0].upper() == "INT":
            if file_list[line_count][1].upper() == "PRINT":
                if file_list[line_count][2][0] == "[":
                    print(ram[int(file_list[line_count][2][1])])
                    line_count += 1
                else:
                    print_statement = ""
                    for i in range(len(file_list[line_count]) - 2):
                        print_statement += \
                            str(file_list[line_count][i + 2]) + " "
                    print(print_statement)
                    line_count += 1
            else:
                location = int(file_list[line_count][2][1])
                int_input = int(input(">> "))
                interrupt(int_input, location)
                line_count += 1
        elif file_list[line_count][0].upper() == "HLT":
            flag = False
