#include <stdio.h>
#include <assert.h>
#include "main.h"
#include "number_to_pair.h"
#include "pair_to_number.h"

void DisplayColorCoding() {
    int PairNumber = 0;
    printf(" Major Color \t Minor Color \t  PairNumber \t\t colorPairNames \n");
    printf("\n-------------------------------------------------------------------\n");
    for (int i = 0 ; i< numberOfMajorColors; i++)
    {
	for (int j = 0 ; j< numberOfMajorColors; j++)
        {	++PairNumber;
 		ColorPair colorPair = GetColorFromPairNumber(PairNumber);
    		char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    		ColorPairToString(&colorPair, colorPairNames);
	    	printf("\t %d\t\t  %d\t\t %d\t\t %s\t\n", i , j ,PairNumber, colorPairNames);
	}
}
int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
     DisplayColorCoding();
    return 0;
}
