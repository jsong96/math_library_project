// Author: Jiwon Song
// File name: MathLib.cpp

#include "MathLib.h"

int absVal(int num) {
    if (num > 0) {return num;}
    else {return -num;}
}

long absVal(long num) {
    if (num > 0) {return static_cast<long>(num);}
    else {return -static_cast<long>(num);}
}

double absVal(double num) {
    if (num > 0) {return static_cast<double>(num);}
    else {return -static_cast<double>(num);}
}

long ceiling(double num) {
    long lnum = static_cast<long>(num);
    if (num > 0) {
        if (num == static_cast<double>(lnum)) {
            return lnum;
        }
        return lnum + 1;
    }
    else {return num - (static_cast<int>(num) % 1);}
}

long floor (double num) {
    if (num > 0) {return num - (static_cast<int>(num) % 1);}
    else {
        long lnum = static_cast<long>(num);
        if (num == static_cast<double>(lnum)) {
            return lnum;
        }
        return lnum - 1;
    }
}

std::string toString(int num, unsigned int radix, bool lower) {
    //default == true
    // if the radix is greater than 36
    if (radix > 36) return "Radix too large";
    else {
        std::string convert = "";
        char c;
        // temporal save of original value
        int tmp = num;
        // get the absolute val of the num
        num = absVal(num);
        // keep dividing the num until it hits 0
        while (num > 0) {
            int remainder = num % radix;
            // if remainder val is bigger than 9, ex 15 = F
            if (remainder > 9) {
                // find the offset to get right ascii letter
                int offset = remainder - 10;
                // for lower case letter
                if (lower) c = offset + 97;
                else c = offset + 65;
            }
            else {
                c = remainder + 48;
            }
            // add the bit to right 
            convert = c + convert;
            // number division by radix val
            num = num / radix;
        }
        if (tmp < 0) {
            convert = "-" + convert;
        }
        return convert;
    }
}

long round (double num, RoundingRule rule) {
    switch (rule) {
        
        case ROUND_HALF_TO_EVEN: {
            // for positivie number
            if (num > 0) {
                if ((num - static_cast<int>(num)) == 0.5) {
                    if ((ceiling(num) % 2) == 0) {return ceiling(num);}
                    else if ((floor(num) % 2) == 0) {return floor(num);}
                    else {return ceiling(num) + 1;}
                }
                else if ((num - static_cast<int>(num)) > 0.5) {return ceiling(num);}
                else {return floor(num);}
            }
            // for negative number
            else {
                if (absVal(num - static_cast<int>(num)) == 0.5) {
                    if ((ceiling(num) % 2) == 0) {return ceiling(num);}
                    else if ((floor(num) % 2) == 0) {return floor(num);}
                    else {return ceiling(num) + 1;}
                }
                else if (absVal(num - static_cast<int>(num)) > 0.5){return floor(num);}
                else {return ceiling(num);}
            }
        }
        case ROUND_HALF_TO_ODD: {
            // for positive number
            if (num > 0) {
                if ((num - static_cast<int>(num)) == 0.5) {
                    if (ceiling(num) % 2 == 0) {return ceiling(num);}
                    else if (floor(num) % 2 == 0) {return floor(num);}
                    else {return ceiling(num) + 1;}
                }
                else if (num - static_cast<int>(num) > 0.5) {return ceiling(num);}
                else {return floor(num);}
            }
            // for negative number
            else {
                if (absVal(num - static_cast<int>(num)) == 0.5) {
                    if (floor(num) % 2 == 1) {return floor(num);}
                    else if (absVal(ceiling(num)) % 2 == 1) {return ceiling(num);}
                    else {return ceiling(num) - 1;}
                }
                else if(absVal(num - static_cast<int>(num) > 0.5)) {return floor(num);}
                else {return ceiling(num);}
            }
        }

        case ROUND_HALF_DOWN: {
            if (num > 0) {
               if ((num - static_cast<int>(num)) == 0.5) {return floor(num);}
               else if ((num - static_cast<int>(num)) > 0.5) {return ceiling(num);}
               else {return floor(num);}
            }
            else {
                if (absVal(num - static_cast<int>(num)) == 0.5) {return ceiling(num);}
                else if (absVal(num - static_cast<int>(num)) > 0.5) {return floor(num);}
                else {return ceiling(num);}
            }
        }

        case ROUND_HALF_UP: {
            if (num > 0) {
                if ((num - static_cast<int>(num)) == 0.5) {return ceiling(num);}
                else if ((num - static_cast<int>(num)) > 0.5) {return floor(num);}
                else {return ceiling(num);}
            }
            else {
                if (absVal(num - static_cast<int>(num)) == 0.5) {return floor(num);}
                else if (absVal(num - static_cast<int>(num)) > 0.5) {return ceiling(num);}
                else {return floor(num);}
            }
        }
        
        // round the number further from zero
        case ROUND_HALF_AWAY_ZERO: {
            if (num > 0) { 
                if ((num - static_cast<int>(num)) == 0.5) {return num + 0.5;}
                else if ((num - static_cast<int>(num)) > 0.5) {return ceiling(num);}
                else {return floor(num);}
            }
            else {
                if (absVal(num - static_cast<int>(num)) == 0.5) {return num - 0.5;}
                else if (absVal(num - static_cast<int>(num)) > 0.5) {return floor(num);}
                else {return ceiling(num);}
            }
        }
        
        // round the number closer to zero
        case ROUND_HALF_TO_ZERO: {
            // -0.5 when the number is positive and +0.5 when the number is negative
            if (num > 0) { 
                if ((num - static_cast<int>(num)) == 0.5) {return num - 0.5;}
                else if ((num - static_cast<int>(num)) > 0.5) {return ceiling(num);}
                else {return floor(num);}
            }
            else {
                if (absVal(num - static_cast<int>(num)) == 0.5) {return num + 0.5;}
                else if (absVal(num - static_cast<int>(num)) > 0.5) {return floor(num);}
                else {return ceiling(num);}
            }
        }

        case ROUND_UP: {return ceiling(num);}

        case ROUND_DOWN: {return floor(num);}

        default: {
           if (num > 0) { 
                if ((num - static_cast<int>(num)) == 0.5) {return ceiling(num);}
                else if ((num - static_cast<int>(num)) > 0.5) {return ceiling(num);}
                else {return floor(num);}
            }
            else {
                if (absVal(num - static_cast<int>(num)) == 0.5) {return ceiling(num);}
                else if (absVal(num - static_cast<int>(num)) > 0.5) {return floor(num);}
                else {return ceiling(num);}
            }
        }
    }
}

double pow (double num, long exponent) {
    if (exponent == 0) {return 1;}
    else if (exponent < 0) {return pow(1 / num, -exponent);}
    else if (exponent % 2 == 0) {return pow(num, exponent / 2) * pow(num, exponent / 2);}
    else {return num * pow(num, exponent / 2) * pow(num, exponent / 2);}
}

int gcd (int num1, int num2) {
    int tmp;
    num1 = absVal(num1);
    num2 = absVal(num2);
    while(num1 != 0) {
        tmp = num1;
        num1 = num2 % num1;
        num2 = tmp;
    }
    return num2;
}
