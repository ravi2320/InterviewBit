/*
Sorted Insert Position
Programming
Binary Search
Easy
41.3% Success

192

10

Bookmark
Asked In:
Problem Description

Given a sorted array A and a target value B, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= 109



Input Format
First argument is array A.

Second argument is integer B.



Output Format
Return an integer, the answer to the problem.



Example Input
Input 1:

 A = [1, 3, 5, 6]
B = 5
Input 2:

 A = [1, 3, 5, 6]
B = 2


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 5 is found at index 2.
Explanation 2:

 2 will be inserted ar index 1.
*/

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int low = 0, high = A.size()-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] < B)
            low = mid + 1;
        else    
            high = mid - 1;
    }
    return low;
}
