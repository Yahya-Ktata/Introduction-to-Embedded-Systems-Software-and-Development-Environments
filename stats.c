/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief The implementation file of the c1m1 assignment
 *
 * Function prototypes for providing statics on an array of numbers, 
 *   and general practice in the "C" language
 *
 * @author Yahya Ktata
 * @date 5/7/2024
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  unsigned char minimum = 0;
  unsigned char maximum = 0;
  float mean = 0;
  unsigned char median = 0;

  
  printf("Array before sorting: \n");
  print_array(&test, SIZE);
  median = find_median(&test, SIZE);
  mean = find_mean(&test, SIZE);
  maximum = find_maximum(&test, SIZE);
  minimum = find_minimum(&test, SIZE);
  print_statistics(minimum, maximum, mean, median);
  sort_array(&test, SIZE);
  printf("Array after sorting: \n");
  print_array(&test, SIZE);


}

void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median){
	printf("The minimum is %d \n", minimum);
	printf("The maximum is %d \n", maximum);
	printf("The mean is %f \n", mean);
	printf("The median is %d \n", median);

}


void print_array (unsigned char *array, unsigned int arrayLength){
	for (int i=0; i<arrayLength; i++){
    printf("%d,", *(array + i));
  }
  printf("\n");

}

unsigned char find_median (unsigned char *array, unsigned int arrayLength){
	unsigned char median = 0;
	median = *(array + (arrayLength / 2) -1);
	return median;
}

float find_mean (unsigned char *array, unsigned int arrayLength){
	unsigned char avg=0;

	// Add up all the numbers in the array
	for(int i=0; i<arrayLength; i++){
    avg+= arrayPtr[i];
  }
  
  // Integer division using Array Length
  return (avg/arrayLength);

}

unsigned char find_maximum (unsigned char *array, unsigned int arrayLength){
	for (int i=1; i<arrayLength; i++){ // start the loop from the second elemnt
    if (*(array + i) > maximum){
      maximum = *(array + i);
    }
  }
  return maximum;
}

unsigned char find_minimum (unsigned char *array, unsigned int arrayLength){
	unsigned char minimum = *array; // initalize the minimum variable with the value of the first array element
	for (int i=1; i<arrayLength; i++){ // start the loop from the second elemnt
    if (*(array + i) < minimum){
      minimum = *(array + i);
    }
  }
  return minimum;

}

void sort_array (unsigned char *array, unsigned int arrayLength){
	unsigned char i, j = 0;
	unsigned char temp;
	// Sort Array
	for(i=0; i<arrayLength; i++){
		for(j=i+1; j<arrayLength; j++){
			if(arrayPtr[i]<arrayPtr[j]){
			temp = arrayPtr[i];
			arrayPtr[i]=arrayPtr[j];
			arrayPtr[j]=temp;
      }
    }
  }

}
