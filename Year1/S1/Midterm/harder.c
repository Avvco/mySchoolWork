#include <stdio.h>
#include <stdlib.h>

int main()
{
    int stop;
    scanf("%d", &stop);

    int price[stop][stop];

    for(int i = 0 ; i < stop ; i++) {
        for(int j = 0 ; j < stop ; j++) {
            scanf("%d", &price[i][j]);
        }
    }

    int time;
    scanf("%d", &time);

    int start_end[time][2];

    for(int i = 0 ; i < time ; i++) {
        for(int j = 0 ; j < 2 ; j++) {
            scanf("%d", &start_end[i][j]);
        }
    }

    int spend = 0;

    for(int i = 0 ; i < time ; i++) {
        spend = spend + price[start_end[i][0]-1][start_end[i][1]-1];
    }

    printf("%d\n", spend);
    printf("%d\n", spend - 1280);
}
