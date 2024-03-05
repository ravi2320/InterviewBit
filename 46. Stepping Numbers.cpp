/*
Stepping Numbers
Programming
Graph Data Structure & Algorithms
Medium
36.4% Success

293

21

Bookmark
Asked In:
Problem Description
 
 

Given A and B you have to find all stepping numbers in the range A to B (both inclusive).

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

For e.g. 123 is a stepping number, but 358 is not a stepping number

 



Problem Constraints
0 <= A <= 104
1 <= B <= 107
A <= B


Input Format
First argument is an integer A.

Second argument is an integer B.

 



Output Format
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



Example Input
Input 1:

 A = 10
 B = 20
 



Example Output
Output 1:

 [10, 12]
 



Example Explanation
Explanation 1:

 The stepping numbers in range [10, 20] are 10, and 12. 
 
*/

void generateAllPaths(int currValue, int A, int B, vector<int> &ans){
    if(currValue > B)
        return;
        
    if(currValue >= A && currValue <= B){
        ans.push_back(currValue);
    }
    
    int lastDigit = currValue % 10;
    
    if(lastDigit != 0){
        generateAllPaths(currValue * 10 + lastDigit -1, A, B, ans);
    }
    
    if(lastDigit != 9){
        generateAllPaths(currValue * 10 + lastDigit + 1, A, B, ans);
    }
}

vector<int> Solution::stepnum(int A, int B) {
    
    vector<int> ans;
    if(A == 0) ans.push_back(0);
    
    for(int i=1; i<=9; i++){
        generateAllPaths(i, A, B, ans);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
