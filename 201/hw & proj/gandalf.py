"""
File: gandalf.py
Name: Wilfried Dim
Date: 02/13/2023
Section: 33
E-mail: wtendjo1@umbc.edu
Description: This program will determine what Lord of the Rings character you
are
"""


if __name__ == "__main__":
    # asks for the user's race
    race = input("Which race are you? (human/dwarf/elf/maiar/hobbit) ")
    # determines character based on race using if/else statements
    #  ".lower" will slightly validate the user's input
    # once it finds the race, it prints out the race
    if race.lower() == "human":
        king_of_gondor = input("Are you the King of Gondor? ")
        if king_of_gondor.lower() == "yes":
            print("You are Aragorn son of Arathorn")
        else:
            frodo_ring = input("Did you try to take a ring from Frodo? ")
            if frodo_ring.lower() == "yes":
                print("You are Boromir")
            else:
                print("You are Theoden")
    elif race.lower() == "elf":
        matrix = input("Were you in the matrix? ")
        if matrix.lower() == "yes":
            print("You are Elrond")
        else:
            print("You are Legolas")
    elif race.lower() == "maiar":
        g_or_e = input("Are you good or evil? ")
        if g_or_e.lower() == "good":
            print("You are Gandalf")
        else:
            forge = input("Did you forge the One Ring? ")
            if forge.lower() == "yes":
                print("You are Sauron")
            else:
                print("You are Saruman")
    elif race.lower() == "hobbit":
        carry = input("Do you carry the One Ring? ")
        if carry.lower() == "yes":
            print("You are Frodo Baggins")
        else:
            gardener = input("Are you are Gardener? ")
            if gardener.lower() == "yes":
                print("You are Samwise")
            else:
                print("You are either Merry or Pippin")
    elif race.lower() == "dwarf":
        print("You are Gimli son of Gloin")
    else:
        print("You are an Orc")
