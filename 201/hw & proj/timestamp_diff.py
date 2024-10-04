"""
File: timestamp_diff.py
Name: Wilfried Dim
Date: 10/18/22
Section: 32
Description: This program will convert the difference of two timestamp
values into seconds
"""


def main():
    # gets time from user
    timestamp_1 = input("Please enter timestamp 1#: ")
    timestamp_2 = input("Please enter timestamp 2#: ")
    timestamp_1 = timestamp_1.split(":")
    timestamp_2 = timestamp_2.split(":")

    # converts any number in string list into an integer
    for i in range(len(timestamp_1)):
        timestamp_1[i] = int(timestamp_1[i])
    for i in range(len(timestamp_2)):
        timestamp_2[i] = int(timestamp_2[i])

    # converts hours and minutes into seconds and converts them into seconds
    timestamp_1_seconds = \
        (timestamp_1[2] + (timestamp_1[1] * 60) + (timestamp_1[0] * 3600))
    timestamp_2_seconds = \
        (timestamp_2[2] + (timestamp_2[1] * 60) + (timestamp_2[0] * 3600))
    new_timestamp_in_seconds = (timestamp_2_seconds - timestamp_1_seconds)
    # converts new timestamp into hours
    new_timestamp_hours = new_timestamp_in_seconds // 3600
    # converts new timestamp into minutes
    new_timestamp_minutes = int((((new_timestamp_in_seconds / 3600)
                                  - new_timestamp_hours) * .6) * 100)
    # converts new timestamp into seconds
    new_timestamp_seconds = \
        int((((((((new_timestamp_in_seconds / 3600) - new_timestamp_hours)
                 * .6) * 100)) - int((((((new_timestamp_in_seconds / 3600)
                                         - new_timestamp_hours) * .6) * 100))))
             * .6) * 100)
    # prints results
    print("That is", new_timestamp_hours, "hour(s),", new_timestamp_minutes,
          "minute(s), and", new_timestamp_seconds, "second(s)")
    print("But that in seconds is :", new_timestamp_in_seconds)


main()
