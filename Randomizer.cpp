#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count[100];

int i = 0;

int maxNumber = 0;
int maxCount = 0;
int totCount = 0;

int loopCount = 0;

int rollCount = 100;
int sampleSize = 10000;

int main()
{
    memset(count, 0x00, sizeof(int) * 100);

    maxNumber = 0;
    maxCount = 0;

    loopCount = 0;

    while (loopCount < rollCount)
    //while(true)
    {
        memset(count, 0x00, sizeof(int) * 100);

        maxNumber = 0;
        maxCount = 0;

        i = 0;

        while (i < sampleSize)
        {
            int r = rand() % 100;

            //printf("%i\n", r);

            count[r]++;

            i++;
        }

        for (int c = 0; c < 100; c++)
        {
            if (count[c] > 0)
            {
                if (count[c] > maxCount)
                {
                    maxNumber = c;
                    maxCount = count[c];
                }

                //printf("%i\t%i\n", c, count[c]);
            }
        }

        if ((maxNumber >= 0) && (maxNumber <= 49))
        {
            printf("max:%i\t%i\n", maxNumber, maxCount);

            totCount++;
        }

        loopCount++;
    }

    printf("tot:%i\n", totCount);
}
