# push_swap - 42 Heilbronn (August 2021)
Because swap_push isn’t as natural<br>

## Usage:
1. Clone it like this:<br>
`git clone --recurse-submodules https://github.com/toni-schmitt/push_swap.git`<br>
This way the libft submodule automatically will get cloned!
2. Compile the program:<br>
`make all`
3. Execute the program:<br>
`./push_swap [Numbers to sort]`
You can put in any amount of numbers. The programm will then print the actions needed to sort the numbers.
4. Check if right actions were used<br>
`./push_swap [Numbers to sort] | ./checker [Numbers to sort]`
If it displays OK everything worked fine!

## How does it work?
For sorting more then 10 numbers I used the [big_sort](https://github.com/toni-schmitt/push_swap/blob/main/src/sorting/big_sort.c "big_sort function file") function.
This function first [indexes](https://github.com/toni-schmitt/push_swap/tree/main/src/sorting/indexing "indexing files") the numbers, so that also negative Integers can be sorted, then proceeds to sort the numbers with a modified version of [Radix Sort](https://www.geeksforgeeks.org/radix-sort/).


###### For more information look into the [subject pdf](https://github.com/toni-schmitt/push_swap/blob/main/push_swap%20subject.pdf)
