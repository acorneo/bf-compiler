# Optimizations made for this compiler (well, for now, interpreter)

## 1. The looped `+` problem
So in most of .bf programs we use `+` multiple times. Sometimes in a loop. Check out this example:
```bf
++++++
[
    >++++++++
    <-
]
>.
```
This program is adding +1 to cell #1 (0-based indexing) **48** times. What if we did a preprocessing? Let's say that we calculate each amount of `+` in each group, so our code becomes something like this pseudocode:
```
(+: 6 times)
[
    > (+: 8 times)
    <-
]
>.
```
This way operation is only done 6 times in the runtime and 14 bits of `+` operation would be processed.  
The same logic can be applied to `-` operation.