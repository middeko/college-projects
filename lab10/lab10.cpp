// lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Painting.h"
#include "Art.h"
#include "Movie.h"
#include <iostream>

using namespace std;

int main() {

    // Instantiation of child objects
    Painting Painting("Mona Lisa");
    Movie Animation("Pinocchio");

    // Art Pointers to child objects (Polymorphism)
    Art* painting1 = &Painting;
    Art* movie1 = &Animation;

    // Painting functions calls
    painting1->CallMyType();
    painting1->CallMyTitle();
    painting1->DescribeMe();

    cout << endl;

    // Movie function calls
    movie1->CallMyType();
    movie1->CallMyTitle();
    movie1->DescribeMe();

    return 0;
}
