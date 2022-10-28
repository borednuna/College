/*
Give a recursive algorithm for finding the maximum of
a finite set of integers, making use of the fact that the
maximum of n integers is the larger of the last integer in
the list and the maximum of the first
n−1 integers in thelist.
*/

#include <stdio.h>

int getMax(int[], int, int, int);

int main() {
    int list[1000];
    int buffer, sequence;
    int i = 0;

    printf("Sequence of number ? ");
    scanf("%d", &sequence);
    printf("Enter sequences: ");

    while (i < sequence)
    {
        scanf("%d", &buffer);
        list[i] = buffer;
        i++;
    }

    printf("%d\n", getMax(list, 0, sequence-1, 0));
}

int getMax(int list[], int currentMax, int index, int currentIndex)
{
    if (currentIndex > index) return currentMax;
    if (list[currentIndex] > currentMax) return getMax(list, list[currentIndex], index, currentIndex + 1);
    if (list[currentIndex] < currentMax) return getMax(list, currentMax, index, currentIndex + 1);
}
