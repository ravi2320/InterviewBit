/*
Merge Overlapping Intervals
Programming
Arrays
Medium
39.6% Success

300

18

Bookmark
Asked In:
Problem Description
 
 

Given a collection of intervals, merge all overlapping intervals.



Problem Constraints
1 <= Total number of intervals <= 100000.



Input Format
First argument is a list of intervals.



Output Format
Return the sorted list of intervals after merging all the overlapping intervals.



Example Input
Input 1:

[1,3],[2,6],[8,10],[15,18]


Example Output
Output 1:

[1,6],[8,10],[15,18]


Example Explanation
Explanation 1:

Merge intervals [1,3] and [2,6] -> [1,6].
so, the required answer after merging is [1,6],[8,10],[15,18].
*/

/**
 * Intuition:
 * Sort the intervals based on their start times.
 * Iterate through the sorted intervals, merging overlapping intervals by comparing the end time of the last interval in the result vector.
 * If the start time of the current interval is greater than the end time of the last interval in the result, add it to the result vector.
 * Otherwise, update the end time of the last interval in the result if needed.
 * 
 * Time Complexity: O(N log N), where N is the number of intervals. The sorting step dominates the time complexity.
 * Space Complexity: O(N), where N is the number of intervals. Additional space is used to store the merged intervals.
 */

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    
    // Sort intervals based on their start times
    sort(A.begin(), A.end(), [](const Interval &a, const Interval &b){
        return a.start < b.start;
    });
    
    vector<Interval> ans;
    
    // Iterate through the sorted intervals
    for(int i = 0; i < n; i++) {
        // If 'ans' is empty or the start time of the current interval is greater than the end time of the last interval in 'ans',
        // add the current interval to 'ans'
        if(ans.empty() || ans.back().end < A[i].start)
            ans.push_back(A[i]);
        // Otherwise, merge overlapping intervals by updating the end time of the last interval in 'ans'
        else if(ans.back().end > A[i].start)
            ans.back().end = max(ans.back().end, A[i].end);
    }
    
    return ans;
}
