#include <stdio.h>
#include <stdlib.h>
//a hybrid filter for a better output, we can take the average of the outputs from both filters. This will balance the smoothing effect of the average filter.
// Function to swap values
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to find median
int find_median(int arr[], int w) 
{
    for(int i = 0; i < w - 1; i++) 
    {
        for(int j = 0; j < w - i - 1; j++) 
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
    return arr[w / 2];
}
// Muchiko filter (average)
void muchiko(int data[], int n, int w) 
{
    printf("Muchiko Filter Output:\n");
    for(int i = 0; i <= n - w; i++) 
    {
        int sum = 0;
        for(int j = 0; j < w; j++) 
        {
            sum += data[i + j];
        }
        printf("%d ", sum / w);
    }
    printf("\n");
}
// Sanchiko filter (median)
void sanchiko(int data[], int n, int w) 
{
    printf("Sanchiko Filter Output:\n");
    for(int i = 0; i <= n - w; i++) 
    {
        int window[10];
        for(int j = 0; j < w; j++) 
        {
            window[j] = data[i + j];
        }
        printf("%d ", find_median(window, w));
    }
    printf("\n");
}
// Hybrid filter (average of Muchiko and Sanchiko)
void hybrid(int data[], int n, int w) 
{
    printf("Hybrid Filter Output:\n");
    for(int i = 0; i <= n - w; i++) 
    {
        int sum = 0;
        int window[10];

        for(int j = 0; j < w; j++) 
        {
            sum += data[i + j];
            window[j] = data[i + j];
        }

        int avg = sum / w;
        int med = find_median(window, w);
        int hybrid = (avg + med) / 2;

        printf("%d ", hybrid);
    }
    printf("\n");
}
int main() 
{
    FILE *fp;
    int data[100], n = 0, w = 3;
    fp = fopen("log.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // Read values from file
    while(fscanf(fp, "%d", &data[n]) != EOF) 
    {
        n++;
    }
    fclose(fp);
    if(n < w) 
    {
        printf("Not enough data for the given window size.\n");
        return 1;
    }
    muchiko(data, n, w);
    sanchiko(data, n, w);
    hybrid(data, n, w); // Call to the new hybrid filter
    return 0;
}

