#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int arr[], int size){
    for (int i = 0; i < size; i++){
        int min_index = i;  //variable for storing the index of the element with minimum value.
        for (int j = i; j < size; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;  //updating the minimum index.
            }    
        }
        swap(arr, min_index, i);
        printarray(arr, size);
    }
}

int main() {
	int arr[N];
	srand(time(0));  //seeding srand function with the current time.
    for (int i = 0; i < N; i++){
	int num = rand()%99 + 1;
	arr[i] = num;
	}
    int counter = 0;    //For storing the number of numbers in the given range.
    for (int i=0; i<N; i++){
        if (arr[i] >= 10 && arr[i] <= 90) counter++;
    }
    printf("Selection sort of arr: \n");
    selection_sort(arr, N);
    printf("The number of elements between 10 and 90 are %d", counter);
    return 0;
}
