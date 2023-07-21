#include <iostream>
using namespace std;
void merge(int *left, int nl, int *right, int nr, int *arr, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < nl && j < nr)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < nl)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < nr)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
void mergeSort(int *arr, int n)
{
    if (n < 2)
    {
        return;
    }
    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, mid, right, n - mid, arr, n);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}