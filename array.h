/**
 * @file array.h
 * 
 * @author Kassidy Maberry
 *
 * @date 2022/03/12
 *  
 * Assignment: Lab 5 
 *
 * @brief header file for array.c
 *
 * @details see array.c for details
 *  
 * @bugs none
 *
 * @todo none
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h> 		/* for size_t declaration */
#define SIZE 10

/* function declarations go here */
void print_array(int a[], size_t size);
int find_max(int arr[], size_t size);
int find_min(int arr[], size_t size);
float midpoint(int max, int min);
void get_count(int arr[], int leg[], int count, size_t size);
int linear_search(int arr[], int search, size_t size);
int sum(int arr[], size_t size);
void reverse(int arr[], size_t size);
void selectionSort(int arr[], int n);
void swap(int *xp, int *yp);
int odd_count(int arr[], size_t size);
int even_count(int arr[], size_t size);
int divisible_count(int arr[], size_t size, int div);
int median(int arr[], size_t size);
float average(int arr[], size_t size);
int sum(int arr[], size_t size);


#endif

