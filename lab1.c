#include <stdio.h>

void prbl2() {
    double velocity_MPH;
    double MILES_INTO_KILOMETERS = 1.60934;
    double velocity_KMPH;

    scanf("%lf", &velocity_MPH);
    velocity_KMPH = velocity_MPH * MILES_INTO_KILOMETERS;
    printf("%.0lf mph is %.2lf in kmph", velocity_MPH, velocity_KMPH);

    return;
}

void prbl1() {
    int age;
    //char name[10];
    scanf("%d", &age);
    //scanf("%s", name);
    printf("Hello guy, aged %d", age);

    return;
}

int main() {
    //prbl1();
    prbl2();
    return 0;
}