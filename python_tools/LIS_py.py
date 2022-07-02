def lis(arr):
    n = len(arr)

    # Declare the list (array) for LIS and initialize LIS
    # values for all indexes
    lis = [1]*n

    prev = [0]*n
    for i in range(0, n):
        prev[i] = i

    # Compute optimized LIS values in bottom up manner
    for i in range (1 , n):
        for j in range(0 , i):
            if arr[i] > arr[j] and lis[i]< lis[j] + 1:
                lis[i] = lis[j]+1
                prev[i] = j

    # Initialize maximum to 0 to get the maximum of all
    # LIS
    maximum = 0
    idx = 0

    # Pick maximum of all LIS values
    for i in range(n):
        if maximum < lis[i]:
            maximum = lis[i]
            idx = i

    seq = [arr[idx]]
    while idx != prev[idx]:
        idx = prev[idx]
        seq.append(arr[idx])

    return (maximum, reversed(seq))
# end of lis function

# Driver program to test above function
arr = [10, 22, 9, 33, 21, 50, 41, 60]
arr1 = [0, 49, 18, 50, 74, 87, 29, 19, 43, 5, 57, 95, 90, 52, 65, 98, 26, 56, 84, 94, 12, 99, 69, 10, 53, 73, 88, 45, 81, 72, 16, 37, 78, 62, 14,    60, 63, 36, 4, 91, 54, 39, 20, 86, 79, 23, 9, 70, 41, 82, 97, 44, 1, 38, 66, 11, 100, 48, 8, 32, 25, 83, 15, 71, 17, 27, 6, 31, 61, 21, 22   , 59, 34, 58, 93, 3, 85, 30, 24, 67, 55, 89, 2, 75, 51, 33, 35, 13, 46, 7, 64, 40, 76, 28, 68, 42, 77, 92, 80, 96]
ans = lis(arr1)
print "Length of lis is", ans[0]
print "The longest sequence is", ", ".join(str(x) for x in ans[1])