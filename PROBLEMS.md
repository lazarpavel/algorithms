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

## P2 - Count the Number of Inversions

```text
Having an array with N elements count the number of inversions required to get the array sorted
See Algorithms Illuminated and merge sort
```

## P3 - The Closest Pair

```text
Given a list of N points on a plane defined by (x,y) coordinates, write an algorithm that will return the closest pair.
Consider that some points can have same x or y coordinates.

d(p1, p2) = sqrt((x1 - x2)^2 + (y1 - y2)^2)

- brute force (calc distance between all pairs - O(n^2))
```

## P4 - Unimodal

```text
You are given an unimodal array of n distinct  elements, meaning that its entries are increasing up to MAX then decreasing order.
Give an algorithm to compute the max value in O(log n) time
```

## P5 - A[i] = i

```text
You are given a sorted array A of n integers which can be positive, negative or zero. Design the fastest algorithm you can
for deciding whether or not there is an index i such that A[i] = i
```


## P5 - Local minimum

```text
You are given an n-bya-n grid of distinct numbers. A number is a local minimum if it is smaller than all its neighbors.
(neighbor is the number above, below, left, right). Use divide-and-conquer design paradigm to compute a local minimum with only O(n)
comparisons between pairs of numbers
```
