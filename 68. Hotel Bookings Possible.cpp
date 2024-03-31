/*
Hotel Bookings Possible
Programming
Arrays
Medium
21.9% Success

358

99

Bookmark
Asked In:
Problem Description
 
 

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Note- If we have arrival and departure on the same date then arrival must be served before the departure.


Problem Constraints
1 <= |A| <= 106
|A|== |B|
1 <= Ai <= Bi <= 108
1 <= C <= 106



Input Format
First argument is an integer array A containing arrival time of booking.

Second argument is an integer array B containing departure time of booking.

Third argument is an integer C denoting the count of rooms.



Output Format
Return True if there are enough rooms for N bookings else return False.

Return 0/1 for C programs.



Example Input
Input 1:

 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1
Input 2:

 A = [1, 2, 3]
 B = [2, 3, 4]
 C = 2


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 At day = 5, there are 2 guests in the hotel. But I have only one room.
Explanation 2:

 At day = 1, there is 1 guest in the hotel.
 At day = 2, there are 2 guests in the hotel. 
 At day = 3, there are 2 guests in the hotel.
 At day = 4, there is 1 guest in the hotel.

 We have two rooms available, which satisfy the demand.
*/

/*
Intuition:
- This function checks whether it's possible to accommodate all advance bookings in a hotel with a given number of rooms.
- It creates event points for each booking's arrival and departure dates.
- Event points are sorted according to the day.
- The function iterates over the sorted event points, keeping track of the number of active guests.
- If at any point, the number of active guests exceeds the number of rooms available, it returns false.
- Otherwise, it returns true.

Time Complexity: O(N log N)
- N is the number of advance bookings.
- Sorting the event points takes O(N log N) time.

Space Complexity: O(N)
- N is the number of advance bookings.
- Additional space is used to store the event points.
*/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    
    // Create event points for each booking's arrival and departure
    vector<pair<int, int>> events;
    for(int i = 0; i < n; i++) {
        events.push_back({arrive[i], 0}); // Arrival event
        events.push_back({depart[i], 1}); // Departure event
    }
    
    // Sort event points according to the day
    sort(events.begin(), events.end());
    
    int activeGuest = 0;
    
    // Iterate over sorted event points
    for(auto event : events) {
        if(event.second == 0)
            activeGuest++; // Increment active guests for arrival
        else
            activeGuest--; // Decrement active guests for departure
            
        // If active guests exceed the number of rooms available, return false
        if(activeGuest > K)
            return false;
    }
    
    // All bookings can be accommodated within available rooms, return true
    return true;
}
