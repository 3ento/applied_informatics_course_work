#include <stdio.h>
#include <math.h>

int distance(int x0, int y0, int x1, int y1) {
    return (int) sqrt(pow(x0-x1, 2)+pow(y0-y1, 2));
}

void prbl3() {
    int x = 12;
    int y = 6;

    double x_squared = pow(x, 2);
    double y_squared = pow(y, 2); 

    double A = 1/(x_squared+1);
    double B = y_squared/(y_squared-1);
    double C = 5/(x_squared+y_squared);
    double D = 1/(x_squared-y_squared);

    double expression = (A+B+C)/D;

    printf("%f", expression);

    return ;
}

void prbl4(){
    int a = 12;
    int b = 6;

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a=%d, b=%d", a, b);

    return;
}

void prbl5(int r) {

    double r_sqruared = pow(r,2);

    double circle_Area = 3.14*r_sqruared;
    double trig_Area = 3*sqrt(3)*r_sqruared;
    double difference = circle_Area-trig_Area;

    printf("%lf(circle) - %lf(trig) = %lf", circle_Area, trig_Area, difference);

    return;
}

void prbl6(int x1, int y1, int x2, int y2, int x3, int y3) {

    int sideA = distance(x1, y1, x2, y2);
    int sideB = distance(x1, y1, x3, y3);
    int sideC = distance(x2, y2, x3, y3);

    int area = sideA+sideB+sideC;

    printf("Area (approximately) = %d", area);
}

int main() {
    //prbl3();
    //prbl4();
    //prbl5(4);
    prbl6(1,1,2,2,1,2);
    return 0;
}