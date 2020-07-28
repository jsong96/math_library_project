// author: Jiwon Song
// file name: demo.cpp
// file description: this file demos all the functions in the library.

#include <iostream>
#include "MathLib.h"


using namespace std;


int main() {
    cout << "absVal: int "<< -5 << " expected: " << 5  << " result: " << absVal(-5) << endl << "\n";
    cout << "absVal: double "<< -4.5 << " expected: " << 4.5  << " result: " << absVal(-4.5) << endl << "\n";
    cout << "absVal: float "<< -8.01 << " expected: " << 8.01  << " result: " << absVal(-8.01) << endl << "\n";
    cout << "ceiling test "<< 4.5 << " expected: " << 5  << " result: " << ceiling(4.5) << endl << "\n";
    cout << "gcd test "<< "3, 6 " << "expected: " << 3  << " result: " << gcd(3, 6) << endl << "\n";
    cout << "pow test "<< "5 2 " << "expected: " << 25  << " result: " << pow(5, 2) << endl << "\n"; 
    cout << "floor test "<< 4.6 << " expected: " << 4  << " result: " << floor(4.6) << endl << "\n";
    cout << "toString test "<< "9 10 true "<< "expected: " << 9  << " result: " << toString(9, 10, true) << endl << "\n";
    cout << "round test "<< 42.00 << " expected: " << 42  << " result: " << round(42.00, ROUND_DOWN) << endl << "\n";
    
    
    return 0;
}

