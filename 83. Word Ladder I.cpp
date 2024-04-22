/*
Word Ladder I
Programming
Graph Data Structure & Algorithms
Hard
28.8% Success

189

24

Bookmark
Asked In:
Problem Description
 
 

Given two words A and B, and a dictionary C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
NOTE:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


Problem Constraints
1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5000


Input Format
The first argument of input contains a string, A.

The second argument of input contains a string, B.

The third argument of input contains an array of strings, C.



Output Format
Return an integer representing the minimum number of steps required to change string A to string B.



Example Input
Input 1:

 A = "hit"
 B = "cog"
 C = ["hot", "dot", "dog", "lot", "log"]
Input 2:

 A = "cat"
 B = "bat"
 C = ["rat"]
Input 3:

 A = "bait"
 B = "pant"
 C = ["a","b"]


Example Output
Output 1:

 5
Output 2:

 2
Output 3:

 0


Example Explanation
Explanation 1:

 "hit" -> "hot" -> "dot" -> "dog" -> "cog"
Explanation 2:

 "cat" -> "bat"
Explanation 3:

 No intermediate words are present in the given dictionary so transformation is not possible. We will return 0 for this case.
*/

// Intuition:
// This class provides a solution to transform one string into another by changing one character at a time.
// It employs a breadth-first search (BFS) approach to explore all possible transformations until the target string is reached.

// Time Complexity: O(n * m * 26)
// - 'n' is the length of the input strings A and B.
// - 'm' is the number of words in the dictionary C.
// - Each transformation involves iterating through the characters of the strings, which takes O(n) time.
// - For each transformation, there are at most 26 possibilities for changing each character.
// - Overall time complexity is O(n * m * 26).

// Space Complexity: O(m)
// - The space complexity is dominated by the unordered_set storing the words in the dictionary C, which requires O(m) space.
// - Additionally, the queue used in BFS can contain up to O(n) elements at a time.

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int solve(string A, string B, vector<string> &C) {
        int n = A.size();
        int level = 0;
        
        // Create a set to store words in the dictionary
        unordered_set<string> st(C.begin(), C.end());
        
        // If the target word B is not in the dictionary, return 0
        if (st.find(B) == st.end())
            return 0;
            
        // Create a queue for BFS and add the starting word A
        queue<string> q;
        q.push(A);
        st.erase(A);
        
        while (!q.empty()) {
            int size = q.size();
            level++;
            
            // Process all words at the current level
            while (size--) {
                string original = q.front();
                q.pop();
                
                // If the current word is the target word B, return the level
                if (original == B)
                    return level;
                    
                // Generate all possible transformations of the current word
                for (int i = 0; i < n; i++) {
                    string curr = original;
                    
                    // Try changing each character of the word to all possible lowercase letters
                    for (char c = 'a'; c <= 'z'; c++) {
                        curr[i] = c;
                        
                        // If the transformed word is in the dictionary and different from the original word
                        if (st.find(curr) != st.end()) {
                            if (curr != original) {
                                q.push(curr);
                                st.erase(curr);
                            }
                        }
                    }
                }
            }
        }
        
        // If the target word B is not reachable from A, return 0
        return 0;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string A = "hit";
    string B = "cog";
    vector<string> C = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << "Minimum transformations required: " << obj.solve(A, B, C) << endl; // Output: 5
    return 0;
}
