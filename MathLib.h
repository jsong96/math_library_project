





#ifndef MATHLIB
#define MATHLIB
#include <string>

/*
return the absolute value of the int
*/
int absVal(int num);


/*
reutrn the absolute value of the long
*/
long absVal(long num);

/*
return the absolute value of the double.
*/
double absVal(double num);


/*
return the ceiling of the double
*/

long ceiling (double num);


/*
return the floor of the double
*/
long floor (double num);

enum RoundingRule {
  ROUND_HALF_UP,
  ROUND_DOWN,
  ROUND_UP,
  ROUND_TO_ZERO,
  ROUND_AWAY_ZERO,
  ROUND_HALF_DOWN,
  ROUND_HALF_TO_ZERO,
  ROUND_HALF_AWAY_ZERO,
  ROUND_HALF_TO_ODD,
  ROUND_HALF_TO_EVEN,
};

/*
return rounded value according to the rounding rule
*/

long round(double num, RoundingRule rule);


/*
Raise the double by the long value
*/
double pow (double num, long exponent);

/*
build a string representation of the int using the unsigned int by the radix
*/
std::string toString (int num, unsigned int radix, bool lower);


/*
Return the greatest common divisor of the two parameters
*/
int gcd (int num1, int num2);


#endif
