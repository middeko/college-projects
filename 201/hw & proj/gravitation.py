"""
File: gravitation.py
Author: Wilfried Dim
Date: 2/6/23
Section: 33
E-mail: wtendjo1@umbc.edu
Description:
    This program will calculate and display the gravitational force between two
    objects
"""


def calculation(mass_1, mass_1_exponent, mass_2, mass_2_exponent, distance,
                distance_exponent):
    # "G" is the gravitational constant
    G = 6.6743 * 10 ** (-11)
    # raises masses by their corresponding exponent to get "real" number
    real_mass_1 = (mass_1 * (10 ** mass_1_exponent))
    real_mass_2 = (mass_2 * (10 ** mass_2_exponent))
    real_distance = (distance * (10 ** distance_exponent))
    # calculates the force
    force = G * ((real_mass_1 * real_mass_2) / (real_distance ** 2))
    # returns force
    return force


if __name__ == "__main__":
    print("Enter the following numbers in scientific notation where the \n"
          "first input is the number and the second is the power "
          "for \nscientific notation.")
    first_mass = float(input("Enter the mass of the "
                       "first object (without exponent): "))
    first_exponent = \
        float(input("Enter the exponent of the first object's mass: "))
    second_mass = float(input("Enter the mass of the "
                        "second object (without exponent): "))
    second_exponent = \
        float(input("Enter the exponent of the second object's mass: "))
    distance = float(input("What is the distance between "
                     "the two objects (without exponent)?:  "))
    distance_exponent = float(input("Enter the exponent of the distance: "))
    final_gravitational_force = calculation(first_mass, first_exponent,
                                            second_mass, second_exponent,
                                            distance, distance_exponent)
    print("The force between these objects is", final_gravitational_force)

