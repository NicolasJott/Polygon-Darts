# Polygon Darts Game
The purpose of this program is to throw at most 10 darts that land inside a input generated polygon on a rectangular "dartboard." 
The polygon can only be hit once to contribute to the score. If the polygon is hit by multiple darts, only the first dart that landed on that polygon will count.

# Please note that all points should be input as fractions
1. The dartboard is drawn by two points, (0,0) and the opposite corner which will be inputted by the user. 
2. The user then inputs the number of polygons on the dart board ranging from 1 - 100.
3. The following loops consist of how many verticies each polygon will have ranging from 3 - 20 (2 points is not a polygon but a straight line).
4. Next the user will input how many darts they would like to throw (this is an integer).
5. This loops depending on the number of darts thrown. The loop will call a function that draws a line through the point and if it intersects a line segment between two points of a polygon, the point is inside the polygon and adds to the score. (Note that a polygon can only be hit once that will count towards the score).
6. The program checks to make sure that no two darts land in the same polygon, if they do, only the first dart throw will count towards the score.
7. The score is then calculated by the area of the dartboard divided by the area of the polygon hit.

# Example 1
Input\
(10/1,10/1)\
2\
3 (0/1,0/1) (3/1,0/1) (2/1,1/1)\
4 (5/1,1/1) (8/1,4/1) (5/1,7/1) (2/1,4/1)\
1\
(4/1,9/2)

Output\
Score: 50 / 9

# Example 2
Input\
(10/1,10/1)\
2\
3 (0/1,0/1) (3/1,0/1) (2/1,1/1)\
4 (5/1,1/1) (8/1,4/1) (5/1,7/1) (2/1,4/1)\
1\
(4/1,1/3)

Output\
Score: 0 / 1

# Example 3
(10/1,10/1)\
2\
3 (0/1,0/1) (3/1,0/1) (2/1,1/1)\
4 (5/1,1/1) (8/1,4/1) (5/1,7/1) (2/1,4/1)\
1\
(2/1,1/3)

Output\
Score: 200 / 3

# Example 4
(10/1,10/1)\
2\
3 (0/1,0/1) (3/1,0/1) (2/1,1/1)\
4 (5/1,1/1) (8/1,4/1) (5/1,7/1) (2/1,4/1)\
3\
(2/1,1/3)\
(5/1,4/1)\
(5/1,5/1)

Output\
Score: 650 / 9

[^1]: Note here that all three dart hit a polygon but dart (2/1,1/3) and (5/1,4/1) hit the same polygon therefore only dart (2/1,1/3) contributes to the score.

