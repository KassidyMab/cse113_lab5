 /**
 * @file lab5_q3.c
 *
 * @author Kassidy Maberry
 *
 * @date 3/12/2022
 *
 * Assignment: Lab 5
 *
 * @brief Tells the user the distance between two points.
 *
 * @details A program that tells the user the distance between two points.
 *
 * @bugs none
 *
 * @todo none
 */
#include <stdio.h>
#include <math.h>


struct point_t{
        double y;
        double x;
};

double dist(struct point_t p1, struct point_t p2);
void point_input(struct point_t *p1);


int main(void)
{
        struct point_t p1;
        struct point_t p2;
        printf("point 1\n-----\n");
        point_input(&p1);
        printf("point 2\n-----\n");
        point_input(&p2);
        double distance = dist(p1, p2);
        printf("The distance between the two points is %lf\n", distance);

        return 0;
}


/**
 * Asks the user for a x,y cord and then writes into the memory location of the
 * struct's x and y variables.
 * @param p1 is the struct that holds the x,y cords.
 */
void point_input(struct point_t *p1)
{
        printf("Enter a point in x,y format: ");
        scanf("%lf, %lf", &p1->x, &p1->y);       
}


/**
 * Does the calculation of the distance using the pythagorean theorm.
 * @param p1 is the first point
 * @param p1 is the second point
 * @return gives the distance bewteen the points.
 */
double dist(struct point_t p1, struct point_t p2)
{
        double total = 0;
        total = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        return total;
}