/*
Give a recursive algorithm for finding a mode
of a list of integers. (A mode is an element in 
the list that occurs at least as often as 
every other element.)

Constraints : 
Sequence not longer than 10^5 and sequence > 0
*/

#include <stdio.h>

int modes[1000];
int getModeValue(int[], int, int, int);
int getModes(int[], int, int, int, int);

int main() {
    int list[100000];
    int buffer, sequence;
    int i = 0;
    int greatest = 0;

    printf("Sequence of number ? ");
    scanf("%d", &sequence);
    printf("Enter sequences: ");

    while (i < sequence)
    {
        scanf("%d", &buffer);
        list[buffer] += 1;
        if (buffer > greatest) greatest = buffer;
        i++;
    }

    int modeValue = getModeValue(list, greatest, 0, 0);
    int howManyModes = getModes(list, greatest, 0, modeValue, 0);

    for (int j = 0; j < howManyModes; j++) printf("%d ", modes[j]);
}

int getModeValue(int list[], int index, int currentIndex, int currentModeValue)
{
    if (currentIndex > index) return currentModeValue;
    if (list[currentIndex] >= currentModeValue) return getModeValue(list, index, currentIndex+1, list[currentIndex]);
    if (list[currentIndex] < currentModeValue) return getModeValue(list, index, currentIndex+1, currentModeValue);
}

int getModes(int list[], int index, int currentIndex, int modeValue, int howManyModes)
{
    if (currentIndex > index) return howManyModes;
    if (list[currentIndex] == modeValue)
    {
        modes[howManyModes] = currentIndex;
        howManyModes += 1;
    }

    return getModes(list, index, currentIndex+1, modeValue, howManyModes);
}