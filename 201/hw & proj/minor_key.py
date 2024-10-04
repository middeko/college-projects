"""
File: minor_key.py
Name: Wilfried Dim
Date: 03/10/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will give the harmonic scale for a specified note
"""


def translate_input(note):
    # if the uppercase version of the full string is already in the list
    # it will return "note.upper()"
    if note.upper() in musical_notes:
        return note.upper()
    else:
        # it will split up the string and convert it into a version found
        # in the list
        # if not in the musical_notes list, it will return invalid input
        note_list = note.split()
        if note_list[0] in musical_notes:
            if note_list[1] == "flat":
                return note_list[0] + "\u266d"
            else:
                return "invalid input"
        else:
            return "invalid input"


def calculate_scale(translated_note):
    # creates an empty list for new scale
    new_scale = []
    note_index = 0
    # finds index of user note
    flag = True
    while flag:
        for i in range(len(musical_notes)):
            if musical_notes[i] == translated_note:
                note_index = i
                flag = False

    # adds each step to the new scale
    new_scale.append(translated_note)
    for i in range(7):
        if i == 0 or i == 2 or i == 3:
            if (note_index + i) <= len(musical_notes):
                new_scale.append(musical_notes[note_index + 2])
            else:
                new_scale.append(musical_notes[i])
        if i == 1 or i == 4 or i == 6:
            if (note_index + i) <= len(musical_notes):
                new_scale.append(musical_notes[note_index + 1])
            else:
                new_scale.append(musical_notes[i])
        if i == 5:
            if (note_index + i) <= len(musical_notes):
                new_scale.append(musical_notes[note_index + 3])
            else:
                new_scale.append(musical_notes[i])
    # returns new scale as a list
    return new_scale


if __name__ == "__main__":
    flag = True
    while flag:
        # initializes list of notes
        musical_notes = ["C", "D\u266d", "D", "E\u266d", 'E', 'F', 'G\u266d',
                         'G', 'A\u266d', 'A', 'B\u266d', 'B']
        user_note = input("Enter a starting note (C, D flat) ")
        if user_note == "quit":
            flag = False
        else:
            t_input = translate_input(user_note)
            if t_input == "invalid input":
                print("There is no starting note", user_note)
            else:
                final_scale = calculate_scale(t_input)
                final_scale_string = ""
                for i in range(len(final_scale)):
                    final_scale_string += final_scale[i] + " "
                # prints final string
                print(final_scale_string)