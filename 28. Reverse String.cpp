/*
Reverse String
Programming
Stacks And Queues
Easy
81.7% Success

43

2

Bookmark
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"
PROBLEM APPROACH :

Complete solution in hints.
*/

string Solution::reverseString(string A) {
    stack<char> st;
    string ans = "";
    for(char ch : A)
        st.push(ch);
    
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}
