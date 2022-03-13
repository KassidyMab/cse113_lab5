/**
 * @file array_struct.c
 * 
 * @author Kassidy Maberry
 *
 * @date 2022/03/12
 *  
 * Assignment: Lab 5 
 *
 * @brief A program that gives statisical data of a range of students.
 *
 * @details The program gives statitiscal data of students. Being their height 
 * and age. The highest, lowest, and the average of each.
 *  
 * @bugs none
 *
 * @todo none
 */


#include "array_struct.h"
#include <stdio.h>


int main(void)
{

	struct data_t data[SIZE];
	struct result_t ans;

	/* data initialization calls */
	init_array(data, 0, 'A', 23, 74);
	init_array(data, 1, 'B', 22, 64);
	init_array(data, 2, 'C', 19, 68);
	init_array(data, 3, 'D', 20, 76);
	init_array(data, 4, 'E', 22, 62);

	ans.young = min_age(data);
	ans.old = max_age(data);
	ans.small = min_height(data);
	ans.tall = max_height(data);
	ans.avgage = avg_age(data);
	ans.avgheight = avg_height(data);

	extremeprint(data, ans);
	avgprint(ans);

	return 0;
}


/**
 * Assigns the given value into the given struct. Creating a student profile.
 * @param data[] is the struct being used to hold the information.
 * @param index is the index of the param where it is being held.
 * @param id the student's letter ID.
 * @param years how old the student is.
 * @param inches how tall the student is in inches.
 */
void init_array(struct data_t data[], int index, char id, int years, int inches)
{
	data[index].age = years;
	data[index].height = inches;
	data[index].subject = id; 
}


/**
 * Figures out the youngest person out of the group.
 * @param data[] the data of all the students.
 * @return returns the index of the youngest student.
 */
int min_age(struct data_t data[])
{
	int index = 0;
	for (int i = 0; i < SIZE; i++){
		if (data[i].age < data[index].age){
			index = i;
		}
	}
	return index;
}

/**
 * figures out the oldest person of the group.
 * @param data[] the data of all the students.
 * @return returns the index of the oldest student.
 */
int max_age(struct data_t data[])
{
	int index = 0;
	for (int i = 0; i < SIZE; i++){
		if (data[i].age > data[index].age){
			index = i;
		}
	}
	return index;
}

/**
 * figures out the shortest of all of the students
 * @param data[] the data of all the students
 *  @return returns the index of the shortest student.
 */
int min_height(struct data_t data[])
{
	int index = 0;
	for (int i = 0; i < SIZE; i++){
		if (data[i].height < data[index].height){
			index = i;
		}
	}
	return index;
}


/**
 * figures out the tallest of all of the students
 * @param data[] the data of all the students.
 * @return returns the index of the tallest student.
 */
int max_height(struct data_t data[])
{
	int index = 0;
	for (int i = 0; i > SIZE; i++){
		if (data[i].height < data[index].height){
			index = i;
		}
	}
	return index;
}

/**
 * Finds the average age of all of the students
 * @param data[] the struct that holds the students' ages.
 * @return gives the average age of all the students.
 */
float avg_age(struct data_t data[])
{
	float total = 0;
	for(int i = 0; i < SIZE; i++){
		total += data[i].age;
	}
	return total / SIZE;
}

/**
 * Figures the average height of the entire class.
 * @param data[] the data of all the students holding the heights.
 * @return the average height of all the students.
 */
float avg_height(struct data_t data[])
{
	float total = 0;
	for(int i = 0; i < SIZE; i++){
		total += data[i].height;
	}
	return total / SIZE;
}


/**
 * prints out all of the data of a given student.
 * @param data the student's information.
 * @param index the index location of said student.
 */
void strprint(struct data_t data, int index)
{
	printf("Struct index: %d\nSubject age: %d\n", index, data.age);
	printf("Subject height: %d inches\nSubject id: %c\n", data.height,
	data.subject);

}


/**
 * prints out the shortest, tallest, oldest, and youngest students found.
 * @param data[] the data of all the students.
 * @param ans the results found from previous funtions.
 */
void extremeprint(struct data_t data[], struct result_t ans)
{
	printf("Shortest\n-----\n");
	strprint(data[ans.small], ans.small);
	printf("-----\nTallest\n-----\n");
	strprint(data[ans.tall], ans.tall);
	printf("-----\nYoungest\n-----\n");
	strprint(data[ans.young], ans.young);
	printf("-----\nOldest\n-----\n");
	strprint(data[ans.old], ans.old);
	printf("-----\n");
}


/**
 * Prints out the average height and age of the given students.
 * @param ans the container for the average height and age.
 */
void avgprint(struct result_t ans)
{
	printf("Average height: %.1f\nAverage age %.1f\n", ans.avgheight,
	ans.avgage);
}
