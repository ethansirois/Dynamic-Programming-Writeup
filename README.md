# Problem Description
For my dynamic programming question, I solved the “Partition Equal Subset Sum” question. It was one of the most interesting top results for dynamic programming questions, so that’s my reasoning for picking it.

Here is the problem description:
“Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.”

It took me a bit of time, but I realized that this problem essentially boils down to the following:

Determine if an array can be split into two subsets of the same sum -->

Determine if the array contains a subset that sums to half of its original sum.

This is because if the array can be split into two portions of the same sum, well then each of those subsets must have a sum of half the array's sum, since they're equal and then they sum to the array's total sum.

# My Algorithm
I just want to first state that since this problem actually ended up being similar to Jeff Erickson's example 3.8: Subset Sum, I think his explanations on the recurrence section of this particular problem and intro to memoization helped a lot with me being able to solve this.

## Recursive
I had to really tune my recursive algorithm, but once I did the DP solution was pretty straightforward. Here's the rundown for the recursion:

Function I/O: takes in a vector, starting index, and target (half the sum of the original array. This is handled before calling the recursive helper function. We can assert inside the recursive function that this will always be a valid split, i.e., the original array sum was even, but that doesn't guarantee that this will be even after the original call!). This will return a bool.

### Base cases: 
Target = 0. The empty set is always a subset of any set. We recurse down to this point if we've removed elements that are exactly target (half the sum of the original array). Therefore the array had a subset of elements that summed to the target, so this is where we return true.

Target went negative or the starting index is not a valid index anymore. This means that we went through the array and didn't find a solution in this particular function call, but we don't know that there aren't other subsets of elements that can sum to the target. We return false here.

### Recurisve Call
All we do for our recurisve call is or the result of the subarray from (starting_index + 1, size of array), meaning we just chop off the first element. This is because at any given array that we are trying to find a subset of elements that sum to a target there are two possibilities: the element at starting_index is included in the subarray sum that I find, or it's not. Although this seems very trivial, this lets us break the problem into a smaller piece. 

To handle the case that the first subset of elements that I find contains the starting_index element, I have to adjust my target value accordingly, since including nums.at(starting_index) means that the new target is: target - nums.at(starting_index), since we wanna break our problem down but still include nums.at(staring_index)'s contribution to the sum towards the target. 

The other option is that nums.at(starting_index) is not included in the first subset I find, so I just ignore it and recurse and search from starting_index + 1 onwards with the same target.

This function works, but it's extremely slow! I tested it on LeetCode and it passed a lot of the smaller tests but timed out of the larger ones.
## DP
This DP solution actually translates pretty nicely. I followed Erickson's recommendation and drew out which subarray sums depend on what, since this is where the dependence and slowness comes from in my recursive solution, and I realized that the previous subset sum evaluations depend on the future subset sum evaluations (since index always increases by one, we know at every step that we will recurse down to the empty set or set containing the last element unless we found a stopping point earlier). So it makes sense to first evaluate the possible subset sums of the last element, then work our way backwards towards the front of the vector. I first did this with a 2d array of booleans, where the rows represented the different "steps" in the problem, where row 0 is the initial array, and the last row is the set containing just the last element. I then made the columns the values 0 through the target inclusive. I marked entry i, j true if the set at the i-th row contained a subset that summed to the j-th element. At every step of the problem, I went through and updated the possible subset sums by adding the current value to the existing true entries. Essentially, if the last element of my array was 3, then the last row would only be true at 3. Then if the second-to-last element was 4, entries 3, 4, and 7 would be true, etc. Then, once we entered something into the target column, we could return true, since we found a subset of elements that sum to the target.

I then realized that if I'm going to be going through and copying the entire row into the row above it (meaning once we mark a value as true it stays true forever), why not just use a 1d vector and update its values? So this is what I did.

This solution was quick and memory efficient. It only used one array of booleans of size target, which is the size of the initial array divided by 2.

It also turns an exponential recusive solution into a O(n^2) $$O(n^2)$$ solution, which was pretty cool. I don't have the proof but would argue that it's less than O(n^2) since the second for loop doesn't even go through all the elements, but at worst case it's O(n^2).

This solution seems more efficient than the 2d array solution that Erickson promotes for finding if a subset of elements in an array sum to a value, as it requires the 2d array instead of 1d and has more loops involved. Maybe I am mistaken, but either way I was happy with the result. It beat 96.5% of solutions on LeetCode!

# Code
You can find the code for the functions in the canPartition.cpp file, and how I timed it in the main.cpp file. I tested my code using -O0 to really see the full difference without any compiler cheats. 

You can check out the code for the graph generation in my "notebooks_Intro.ipynb" file.

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

### 98: 10.8211 vs 0.000186417

### 106: 172.828 vs 0.000254875

Not sure why those two become "hyperlinked", but look at the difference! And vector size is only around 100 at those tests!

