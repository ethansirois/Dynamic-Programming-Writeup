# Problem Description
For my dynamic programming question, I solved the “Partition Equal Subset Sum” question. It was one of the most interesting top results for dynamic programming questions, so that’s my reasoning for picking it.

Here is the problem description:
“Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.”

It took me a bit of time, but I realized that this problem essentially boils down to the following:

Determine if an array can be split into two subsets of the same sum -->

Determine if the array contains a subset that sums to half of its original sum.

This is because if the array can be split into two portions of the same sum, well then each of those subsets must have a sum of half the array's sum, since they're equal and then they sum to the array's total sum.

# My algorithm
I had to really tune my recursive algorithm, but once I did the DP solution was pretty straightforward. Here's the rundown for the recursion:



# Code
You can find the code for the functions in the canPartition.cpp file, and how I timed it in the main.cpp file. I tested my code using -O0 to really see the full difference without any compiler cheating.

# Results
My DP solution was magnitudes faster than the recursive implementation!

Here's a normal plot of the runtimes for recursion vs dynamic programming. It's almost hard to see the DP line because of how much faster it is!
![Screenshot 2023-11-11 at 11 48 05 PM](https://github.com/ethansirois/dp/assets/114622541/df1cc8b4-9cd4-4e9f-9439-1ccadd64830d)

And here's the loglog plot of the recursive implementation vs my dynamic programming implementation
![Screenshot 2023-11-11 at 11 47 52 PM](https://github.com/ethansirois/dp/assets/114622541/48e0cf97-e23c-47bd-b729-29743b14d50d)

And here's the raw output of times:

## Sizes of vectors were: 

[10, 18, 26, 34, 42, 50, 58, 66, 74, 82, 90, 98, 106]

## Recursive times: 

[3.083e-06, 5.25e-06, 1.5792e-05, 0.000292417, 0.000740042, 0.00198788, 0.0232612, 0.042198, 0.0837106, 1.33687, 2.67482, 10.8211, 172.828]

## DP times: 

[9.59e-07, 1.875e-06, 4.125e-06, 1.0208e-05, 1.7458e-05, 2.4792e-05, 5.125e-05, 5.8792e-05, 7.8709e-05, 0.000110875, 0.000139541, 0.000186417, 0.000254875]
