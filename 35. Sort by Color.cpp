/*
Sort by Color
Programming
Two Pointers
Medium
58.8% Success

250

17

Bookmark
Asked In:
Problem Description
 
 

Given an array with N objects colored red, white, or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent red, white, and blue, respectively.

Note: Using the library sort function is not allowed.



Problem Constraints
1 <= N <= 1000000
0 <= A[i] <= 2


Input Format
First and only argument of input contains an integer array A.


Output Format
Return an integer array in asked order


Example Input
Input 1 :
    A = [0 1 2 0 1 2]
Input 2:

    A = [0]


Example Output
Output 1:
    [0 0 1 1 2 2]
Output 2:

    [0]


Example Explanation
Explanation 1:
    [0 0 1 1 2 2] is the required order.
*/

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
   int low = 0, mid = 0, high = A.size()-1;
    while(mid <= high){
        if(A[mid] == 0){
            swap(A[low], A[mid]);
            low++;
            mid++;
        }
        else if(A[mid] == 1){
            mid++;
        }
        else{
            swap(A[mid], A[high]);
            high--;
        }
    }
}
