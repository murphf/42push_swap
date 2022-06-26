//#include "push_swap.h"
#include "bitsStdcpp.hpp"
using namespace std;
// Utility function to print LIS 
void printLIS(vector<int>& arr) 
{ 
    for (int x : arr) 
        cout << x << " "; 
    cout << endl; 
} 
/* C VERSION */
/*
* arr being the array containing the LIS
* n bein
*/
void	printLIS(int *arr, int	n)
{
	for (int i = 0; i < n; i++)
		printf ("%d ", arr[i]);
}

int *constructPrintLis(int *arr, int n, t_node   **stack_a)
{
   int  **L;
   int    i;
   int    n_lis;
   int    x;

    n_lis = //lenght_of_lis
    x = 1;
    L = (int **)malloc(sizeof(int *) * n_lis);
    if (!l)
        return ;
    i = 0;
    L[0] = (int *)malloc(sizeof(int) * n_lis);
    if (!L[0])
        return (NULL);
    L[0][0] = arr[0];
    k = 0;
    for (i = 1; i < n_lis; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if((arr[i] > arr[j]) && ()
        }
        L[i] = (int *)malloc(sizeof(int) * n_lis);
        if (!L[i])
            return (NULL);
        L[i][k] = ()
        k++;
    }
}
// Function to construct and print Longest Increasing 
// Subsequence 
void constructPrintLIS(int arr[], int n) 
{ 
    
    /*
    * 2D vecteur of type int ----> equivalent to a 2D array
    * a vector is a dynamic arrays
    * with the ability to resize itself automatically when an element is inserted or deleted
    */
    vector<vector<int> > L(n);  
  
    // L[0] is equal to arr[0] 
    L[0].push_back(arr[0]); 
  
    // start from index 1 
    for (int i = 1; i < n; i++) 
    { 
        // do for every j less than i 
        for (int j = 0; j < i; j++) 
        { 
            /* L[i] = {Max(L[j])} + arr[i] 
            where j < i and arr[j] < arr[i] */
            if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1)) 
                L[i] = L[j]; 
        } 
  
        // L[i] ends with arr[i] 
        L[i].push_back(arr[i]); 
    } 
  
    // L[i] now stores increasing sub-sequence of 
    // arr[0..i] that ends with arr[i] 
    vector<int> max = L[0]; 
  
    // LIS will be max of all increasing sub- 
    // sequences of arr 
    for (vector<int> x : L) 
        if (x.size() > max.size()) 
            max = x; 
  
    // max will contain LIS 
    printLIS(max); 
} 
  
// Driver function 
int main() 
{ 
    int arr[] = {0, 49, 18, 50, 74, 87, 29, 19, 43, 5, 57, 95, 90, 52, 65, 98, 26, 56, 84, 94, 12, 99, 69, 10, 53, 73, 88, 45, 81, 72, 16, 37, 78, 62, 14, 60, 63, 36, 4, 91, 54, 39, 20, 86, 79, 23, 9, 70, 41, 82, 97, 44, 1, 38, 66, 11, 100, 48, 8, 32, 25, 83, 15, 71, 17, 27, 6, 31, 61, 21, 22, 59, 34, 58, 93, 3, 85, 30, 24, 67, 55, 89, 2, 75, 51, 33, 35, 13, 46, 7, 64, 40, 76, 28, 68, 42, 77, 92, 80, 96 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // construct and print LIS of arr 
    constructPrintLIS(arr, n); 
  
    return 0; 
} 