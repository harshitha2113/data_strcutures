#include<stdio.h>
int partition(int * arr, int low, int high)
{
    int pivot = low, p = low + 1, q = high;
    while(p <= q)
    {
        while(arr[pivot] >= arr[p])
            p++;
        while(arr[pivot] < arr[q])
            q--;
        if(p < q)
        {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }
    int temp1 = arr[pivot];
    arr[pivot] = arr[q];
    arr[q] = temp1;
    return q;
}
void Quick_sort(int * arr, int low, int high)
{
    if(low < high)
    {
        int ind = partition(arr,low,high);
        Quick_sort(arr,low,ind - 1);
        Quick_sort(arr,ind + 1, high);
    }
}
int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("enter elements : ");
    for(int i = 0; i < size; i++)
            scanf("%d",&arr[i]);
    int low = 0, high = size - 1;
    Quick_sort(arr,low,high);
    printf("sorted array is : ");
    for(int i = 0; i < size; i++)
            printf("%d ", arr[i]);
    printf("\n");
}
