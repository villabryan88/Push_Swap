#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM 32
int main()
{
    int array[NUM];
    int x, p;
    int count;
    int i=0;

    srand(time(NULL));

    for(count=0;count<NUM;count++){
        array[count]=rand()%NUM+1;
    }

    while(i<NUM){
        int r=rand()%NUM+1;

        for (x = 0; x < i; x++)
        {
            if(array[x]==r){
                break;
            }
        }
        if(x==i){
            array[i++]=r;
        }
    }
    for(p=0;p<NUM;p++){
        printf("%d ", array[p]);
    }
    return 0;
}
