# INTERVIEW PROBLEMS

## P1 - Equal Sum Arrays With Minimum Number of Operations

```text
You are given two arrays of integers nums1 and nums2, possibly of different lengths.
The values in the arrays are between 1 and 6, inclusive.
In one operation, you can change any integer's value in any of the arrays to any value between 1 and 6, inclusive.

Return the minimum number of operations required to make the sum of values in nums1 equal to the sum of values in nums2.
Return -1​​​​​ if it is not possible to make the sum of the two arrays equal.
```

## P2 - Car Fleet II

```text
There are n cars traveling at different speeds in the same direction along a one-lane road.
You are given an array cars of length n, where cars[i] = [position[i], speed[i]] represents:

position[i] is the distance between the ith car and the beginning of the road in meters. It is guaranteed that position[i] < position[i] + 1.
speed[i] is the initial speed of the ith car in meters per second.

For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position.
Once a car collides with another car, they unite and form a single car fleet.
The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.

Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1
if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.
```
