/*
 * Sort a list of integers using the Selection Sort algorithm.
 * The input parameters are an array of integers (Data) and
 * the number (N) of elements in the array. The array is sorted
 * in-place in ascending order.
 */

void selsort(int Data[], int N)
{
    int start, i, minix, temp;

    for (start=0; start < N-1; start++)
    {
        minix = start;
        for (i=start+1; i < N; i++)
        {
            if (Data[i] < Data[minix])
            {
                minix=i;
            }
        }

        if (minix != start)
        {
            temp = Data[minix];
            Data[minix] = Data[start];
            Data[start] = temp;
        }
    }
}
