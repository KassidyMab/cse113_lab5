 /**
 * @file lab5_q2.c
 *
 * @author Kassidy Maberry
 *
 * @date 3/12/2022
 *
 * Assignment: Lab 5
 *
 * @brief Shows how enumeration works
 *
 * @details Shows how enumeration works by printing out the enumerated values
 * and says what they are.
 *
 * @bugs none
 *
 * @todo none
 */
#include <stdio.h>

enum color
{
        RED = 18, ORANGE, YELLOW = 5, GREEN, BLUE, INDIGO = 14, VIOLET
};

void main()
{
        printf("Red = %d\n", RED);
        printf("Orange = %d\n", ORANGE);
        printf("yellow = %d\n", YELLOW);
        printf("Green = %d\n", GREEN);
        printf("Blue = %d\n", BLUE);
        printf("Indigo = %d\n", INDIGO);
        printf("Violet = %d\n", VIOLET);
}