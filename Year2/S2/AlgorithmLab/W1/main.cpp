int* sort (int* A, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int j = i, val = A[j];
        while (j > 0 && !(A[j-1] <= val))
        {
            A[j] = A[j-1];
            --j;
        }
        A[j] = val;
    }
    return A;
}
