/*
Devise a recursive algorithm for computing the greatest
common divisor of two non-negative integers a and b
with a < b using the fact that gcd(a, b)=gcd(a, b−a).
*/

#include <stdio.h>
#include <math.h>

int getGCD(int, int);

int main() {
    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("%d\n", getGCD(a, b));
}

int getGCD(int a, int b)
{
    if (b == 0) return a;
    return getGCD(b, abs(b - a));
}
