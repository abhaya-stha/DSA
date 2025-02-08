#include <stdio.h>
void swap(int* a, int* b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) 
{
    
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}


void quicksort(int arr[], int low, int high) 
{
    if (low < high) {
        
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


int main()
{
    int arr[20],n;
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    printf("Enter %d numbers:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("After sorting:\n");
     for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}