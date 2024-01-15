/*
Max Product Subarray
Programming
Dynamic Programming
Medium
36.4% Success

322

6

Bookmark
Asked In:
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
*/

//Time Complexity = O(n2) Space Complexity = O(1) 
//It is not optimal solution it gives TLE
int Solution::maxProduct(const vector<int> &A) {
    int product = 1, maxi = INT_MIN , n = A.size();
    
    for(int i=0; i<n; i++){
        product = 1;
        for(int j=i; j<n; j++){
            if(product == 0) product = 1;
            product = product * A[j];
            maxi = max(maxi, product);
        }
    }
    return maxi;
}

//It is most Optimal Solution it gives time complexity O(n), Space Complexity = O(1)
int Solution::maxProduct(const vector<int> &A) {
    int suffix = 1, prefix = 1, maxi = INT_MIN , n = A.size();
    
    for(int i=0; i<n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        
        prefix = prefix * A[i];
        suffix = suffix * A[n-i-1];
        
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}
