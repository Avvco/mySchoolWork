# Algorithm Lab, Week 1: Sort
410921311 李佾

## Description  
In computer science, sorting algorithm is an algorithm that puts elements of a list in a certain
order (From Wikipedia). Thus, we can define sorting algorithms as followed:

:::info  
Instance: a list of elements 𝐴 = (𝑎1, 𝑎2, … , 𝑎𝑛) and a comparator 𝐶(𝑣0, 𝑣1) → {𝑇𝑟𝑢𝑒, 𝐹𝑎𝑙𝑠𝑒}  

Result: a list 𝐵 = (𝑏1, 𝑏2, … , 𝑏𝑛) that {𝑎1, 𝑎2, … , 𝑎𝑛} = {𝑏1, 𝑏2, … , 𝑏𝑛} and for all 1 < 𝑖 ≤ 𝑛, 𝐶(𝑏𝑖−1, 𝑏𝑖) is 𝑇𝑟𝑢𝑒.  
:::  
If we want to sorting a list of integers by increasing order, our comparator, we should use ≤ as our comparator. Please design an algorithm to sorting integers in increasing order. 


## Algorithm Design  

Insertion sort will divide data to 2 partitions, sorted and unsorted.
1. Let first element as sorted part and the others as unsorted part.  
2. Insert an unsorted element 𝑣𝑖 to sorted part and keep them in certain   order.  
    2.1 Find minimum 𝑗 that 𝐶(𝑣𝑗, 𝑣𝑖) = 𝐹𝑎𝑙𝑠𝑒.  
    2.2 Shifting all 𝑣𝑘 that 𝑘 ≥ 𝑗.  
    2.3 Insert 𝑣𝑖 to current position.  
3. Repeat step 2 until unsorted part contains no elements.  

## Implementation  
```cpp=
int* sort (int* A, int n)
{
    for (int i = 1; i < n; ++i) // N - 1
    {
        int j = i, val = A[j]; // C
        while (j > 0 && !(A[j-1] <= val)) // M, when A[j-1]>val
        {
            A[j] = A[j-1]; // C
            --j; // C
        }
        A[j] = val; // C
    }
    return A;
}
```

## Analysis  
### Space complexity  
Assume that instance is an 𝑛 elements array.  
⚫ Instance: 𝑛 values and 1 index (A, n)  
⚫ Divider: 1 index (i)  
⚫ Ordering maintain: 1 index (j) and 1 value(val)  
Totally needs 𝑛 + 1 values and 3 indices, so the ==Space complexity is $𝑂(𝑛)=n$==

---
### Time complexity  
#### Bast case  
When completly sorted, ```A[j-1]``` $\le$ ```val```. So the while loop will not be executed.  
So $m=0$, ==Time Complixity is $O(n-1) \in O(n) = n$==  
#### Worst case  
When element is in complete reverse order, the while loop will execute exactly the time as the for loop.  
So $m=n$, ==Time Complixity is $O((n-1)^2) \in O(n^2) = n^2$==  
