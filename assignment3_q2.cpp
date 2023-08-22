#include <stdio.h>
#define MAX_SIZE 100

void printarray(char arr[], int size){
    for (int i=0; i<size; i++) printf("%c ", arr[i]);
    printf("\n");
}

void swap(char arr[], int i, int j){
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble_sort(char arr[], int size){
    int swapped = 0;    //Variable to check if array is already sorted or not.
    for (int i=0; i<size; i++){
        for (int j=0; j<size-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr, j, j+1);
                swapped = 1;
            }
        }
        printarray(arr, size);
        if (!swapped) return;   //if array is sorted already then simply terminate the function.
    }
}

void insertion_sort(char arr[], int size){
    for (int i=0; i<size; i++){
        int j=i-1;
        int key = arr[i];
        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        printarray(arr, size);
    }
}

int Union(char arr1[], char arr2[], char arr3[], int size_arr1, int size_arr2){
    int index = 0;  //storing the indices of the new array.
    int count_arr[256];     //All possible ASCII Values.
    for (int i=0; i<256; i++){
        count_arr[i] = 0; //All are initialized to zero first.
    }

    for (int x=0; x<size_arr1; x++){
        if (count_arr[arr1[x]] == 0){  //Checking whether the element is not already present.
            arr3[index] = arr1[x];  //Updating the array to store the union with the element.
            index++;
            count_arr[arr1[x]]++; //incrementing
        }
    }
    for (int y=0; y<size_arr2; y++){
        if (count_arr[arr2[y]] == 0){
            arr3[index] = arr2[y];
            index++;
            count_arr[arr2[y]]++;
        }
    }
    
    insertion_sort(arr3, index);
    return index;
}


int main() {
    int n1;
    printf("n1= ");  //Variable to store the size of array1
    scanf("%d", &n1);
    char arr1[n1];
    printf("Enter character arr1: ");
    for (int i=0; i<n1; i++){
        scanf(" %c", &arr1[i]);
    }
    
    int n2;
    printf("n2= ");  //Size of array 2
    scanf("%d", &n2);
    char arr2[n2];
    printf("Enter character arr2: ");
    for (int i=0; i<n2; i++){
        scanf(" %c", &arr2[i]);
    }
    
    printf("Bubble sort of arr1: \n");
    bubble_sort(arr1, n1);
    printf("Insertion sort of arr2: \n");
    insertion_sort(arr2, n2);
    printf("Union of arr1 and arr2: \n");
    char(arr3[2*MAX_SIZE]);
    
    printf("The size of arr3 is %d.", Union(arr1, arr2, arr3, n1, n2)); //Returning the size of the union of the two arrays.
    return 0;
}
