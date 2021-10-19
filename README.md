# CS361-ADV-ALGORITHMS-DATA-STRUCTURES---Homework02

In this assignment I used a stack to determine if an input file is properly balanced in the sense that:
* Every `(` must be terminated by a `)`, and every `)` must terminate some `(`.
* Every `[` must be terminated by a `]`, and every `]` must terminate some `[`.
* Every `{` must be terminated by a `}`, and every `}` must terminate some `{`.
* Matching pairs of thr above characters may be nested (i.e. one within another), but may not overlap.
* All other characters are ignored.

Our assignment was to implement the `Check` function to read the input file and update the current state of the stack. Additonally, our assignment was also to implement the `checkMatch` function to check the current state of the stack and provide any necessary output. Once the process is finished the word "Done" is outputted on a single line. (The program only detects unbalanced pairs, it does not recover from them.)
