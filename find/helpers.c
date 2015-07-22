/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
void swap(int *a, int *b)  
{  
    int tmp = *a;  
    *a = *b;  
    *b = tmp;  
}  
  
int partition(int a[], int low, int high)  
{  
    int privotKey = a[low];                             //基准元素  
    while(low < high){                                   //从表的两端交替地向中间扫描  
        while(low < high  && a[high] >= privotKey) --high;  //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端  
        swap(a+low, a+high);  
        while(low < high  && a[low] <= privotKey ) ++low;  
        swap(a+low, a+high);  
    }    
    return low;  
}  
  
  
void quickSort(int a[], int low, int high){  
    if(low < high){  
        int privotLoc = partition(a,  low,  high);  //将表一分为二  
        quickSort(a,  low,  privotLoc -1);          //递归对低子表递归排序  
        quickSort(a,   privotLoc + 1, high);        //递归对高子表递归排序  
    }  
}  
bool search(int value, int array[], int n)
{
    // TODO: implement a searching algorithm
    int b = 0;
    int e = n;
    int mid;
    if (array[b] > value)
    return false;
    if (array[b] == value)
    return true;
    else
    {   
        while ((b - e) != 1)
        {
            mid = (b+ e) / 2;
            if (value == array[mid])
            return true;
            else
            if (value < array[mid])
            e = mid;
            else
            b = mid;
        }
    }   
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm
    int head = 0;
    int tail = n -1;
    quickSort(values,head,tail);
    return;
}
