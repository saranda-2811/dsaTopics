A hostel has NN rooms in a straight line. It has to accommodate XX people. Unfortunately, out of these XX people, YY of them are infected with chickenpox. Due to safety norms, the following precaution must be taken:

No person should occupy a room directly adjacent to a room occupied by a chickenpox-infected person. In particular, two chickenpox-infected people cannot occupy adjacent rooms.
For example, if room 44 has a chickenpox-infected person, then nobody should occupy rooms 33 and 55. Similarly, if room 11 has a chickenpox-infected person then nobody should occupy room 22.

What's the minimum value of NN for which all the people can be accommodated in the hostel, following the above condition?

Input Format
The first line of input contains a single integer TT — the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains two integers XX and YY — the total number of people and the number of chickenpox-infected people.
Output Format
For each test case, output on a new line a single integer — the minimum value of NN for which all the people can be accommodated in the hostel.

Constraints
1≤T≤2001≤T≤200
1≤X≤10001≤X≤1000
0≤Y≤X0≤Y≤X
Sample Input 1
3
4 0
5 3
3 3
Sample Output 1
4
8
5
Explanation
Note: Below, CC represents a room occupied by a chickenpox-infected person, NN represents a room occupied by an uninfected person, and __ represents an empty room.

Test case 11: One of the possible ways to accommodate the people in 44 rooms is:

NN NN NN NN

Test case 22: One of the possible ways to accommodate the people in 88 rooms is:

CC __ CC __ NN NN __ CC

Test case 33: One of the possible ways to accommodate the people in 55 rooms is:

CC __ CC __ C
