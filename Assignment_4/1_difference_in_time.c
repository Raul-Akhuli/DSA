#include <stdio.h>

typedef struct time {
    int hour;
    int min;
    int sec;
}Time;

int timeInSeconds(Time time){
    int timeSeconds;
    timeSeconds = time.hour * 3600 + time.min * 60 + time.sec;
    return timeSeconds;
}

void main(){
    Time startTime, stopTime;
    int start, end;

    printf("Enter the start time. \n");
    printf("Enter hours, minutes and seconds: ");
    scanf("%d %d %d", &startTime.hour,
        &startTime.min,
        &startTime.sec);

    printf("Enter the stop time. \n");
    printf("Enter hours, minutes and seconds: ");
    scanf("%d %d %d", &stopTime.hour,
        &stopTime.min,
        &stopTime.sec);

    start = timeInSeconds(startTime);
    end = timeInSeconds(stopTime);

    printf("Difference between start time and end time is %dseconds",end-start);
}