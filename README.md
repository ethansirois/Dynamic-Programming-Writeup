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

## Recursive Times vs DP Times: 
Format-- $vector_size: $recursive_time vs $dp_time
10: 3.083e-06 vs 9.59e-07

18: 5.25e-06 vs 1.875e-06

26: 1.5792e-05 vs 4.125e-06

34: 0.000292417 vs 1.0208e-05

42: 0.000740042 vs 1.7458e-05

50: 0.00198788 vs 2.4792e-05

58: 0.0232612 vs 5.125e-05

66: 0.042198 vs 5.8792e-05

74: 0.0837106 vs 7.8709e-05

82: 1.33687 vs 0.000110875

90: 2.67482 vs 0.000139541

98: 10.8211 vs 0.000186417

106: 172.828 vs 0.000254875

