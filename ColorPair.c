#include "ColorPair.h"

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);


void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}


ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (MajorColor_type)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (MinorColor_type)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

void DisplayColorCoding()
{
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

}
