/*
Basic and extended euclidean algorithm
https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
*/

int extendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a%b);
}



/*
 *  Time complexity: O(log(min(a, b)))
 *  Worst case occurs when the two numbers are consecutive fibonacci numbers
 *  i.e. a = Fn, b = Fn-1 
 *  By Binet's formula Fn = (phi)^n/root(5) = k^n
 *  After n iterations a and b are reduced to a = 2, b = 1
 *  Thus GCD is of logarithmic complexity (it reduces k^n to k in n steps)
 * 
 * Extended Euclidean algorithm finds integer coefficients x and y such that: ax + by = gcd(a, b) 
 * It particularly useful when a and b are coprime 
 * since x is the modular multiplicative inverse of “a modulo b”, 
 * and y is the modular multiplicative inverse of “b modulo a”.
*/