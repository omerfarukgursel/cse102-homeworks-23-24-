#include <stdio.h>
#include <math.h>

#define EPSILON 0.001
#define NUMBERS 10

// name of quality: GURSEL CODING 🔥🔥🔥

float calculate_slope(float x1, float y1, float x2, float y2)
{
    if (x1 != x2){
        return (y2 - y1) / (x2 - x1);
    }
    else{
        return  x1+EPSILON;
    }
}

float calculate_distance(float x1, float y1, float x2, float y2)
{
    return sqrt((pow(x1 - x2, 2)) + (pow(y1 - y2, 2)));
}


void main()
{
    // defining variables
    float sumclass1_x = 0, sumclass1_y = 0;
    float sumclass2_x = 0, sumclass2_y = 0;
    float average1_x, average1_y, average2_x, average2_y;
    float conlineslope, seplineslope;
    float midpoint_x, midpoint_y;
    float testX, testY;
    int i;
    //taking some inputs
    for (i = 0; i < NUMBERS; i++)
    {
        float x, y;
        scanf("%f %f", &x, &y);
        sumclass1_x = sumclass1_x + x;//summation for x
        sumclass1_y = sumclass1_y + y;//summation for y
    }
    for (i = 0; i < NUMBERS; i++)
    {
        float x, y;
        scanf("%f %f", &x, &y);
        sumclass2_x = sumclass2_x + x;//summation for x
        sumclass2_y = sumclass2_y + y;//summation for y
    }
    //finding average point
    average1_x = sumclass1_x / NUMBERS;
    average1_y = sumclass1_y / NUMBERS;
    average2_x = sumclass2_x / NUMBERS;
    average2_y = sumclass2_y / NUMBERS;

    conlineslope = calculate_slope(average1_x, average1_y, average2_x, average2_y);
    seplineslope = (-1 / conlineslope);//finding seperating line slope

    midpoint_x = (average1_x + average2_x) / 2;//finding midpoint x axis
    midpoint_y = (average1_y + average2_y) / 2;//finding midpoint y axis

    printf("midpoint = %.1f %.1f\n", midpoint_x, midpoint_y);//printing on the screen
    printf("separating line slope = %.1f\n", seplineslope);

    while (1)//taking test inputs until user enters an unacceptable input
    {
        int input = scanf("%f %f", &testX, &testY);
        if (input != 2)
        {
            break;
        }
    //calculating distances
    float distance1 = calculate_distance(testX, testY, average1_x, average1_y);

    float distance2 = calculate_distance(testX, testY, average2_x, average2_y);

    if (distance1 < distance2)
    {
        printf("class1, distance = %.1f\n", distance1);
    }
    else
    {
        printf("class 2, distance = %.1f\n", distance2);
    }
}
}

