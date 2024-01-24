/*
Largest Number
Programming
Arrays
Medium
20.8% Success

550

72

Bookmark
Asked In:
Problem Description
 
 

Given a list of non-negative integers, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.


Problem Constraints
1 <= |A| <= 105
0 <= Ai <= 109


Input Format
The first argument is an integer array A.


Output Format
Return a string representing the largest number formed


Example Input
A = [3, 30, 34, 5, 9]


Example Output
9534330


Example Explanation
Largest possible number that can be formed is 9534330
*/

string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> arr;
    
    for (int num : A) {
        arr.push_back(to_string(num));
    }

    sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
        return a + b > b + a;
    });

    string res = "";
    for (const string &s : arr) {
        res += s;
    }

    return res[0] == '0' ? "0" : res;
}
