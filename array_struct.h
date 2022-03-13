/**
 * @file array_struct.h
 * 
 * @author Kassidy Maberry
 *
 * @date 2022/03/12
 *  
 * Assignment: Lab 5 
 *
 * @brief header file for array.c
 *
 * @details see array_struct.c for details
 *  
 * @bugs none
 *
 * @todo none
 */

#ifndef ARRAY_STRUCT_H_
#define ARRAY_STRUCT_H_


#define SIZE 5

struct data_t {

	int age;  /* age of the subject */
	int height;  /* height of subject in inches */
	char subject; 	/* one capital letter id for subject */
	
};


struct result_t {
	int young, old, tall, small;
	float avgage, avgheight;
};

void init_array(struct data_t data[], int index, char id, int years, int inches);

int min_age(struct data_t data[]);
int max_age(struct data_t data[]);
int min_height(struct data_t data[]);
int max_height(struct data_t data[]);
float avg_age(struct data_t data[]);
float avg_height(struct data_t data[]);
void extremeprint(struct data_t data[], struct result_t ans);
void strprint(struct data_t data, int index);
void avgprint(struct result_t ans);

#endif
