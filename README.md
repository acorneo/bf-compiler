# Brainfuck compiler 

The point of this project was that I actually start doing at least something and not just watching Reels.  

Also people can learn about this beatiful programming language. For now because of Youtubers it's considered really hard, which really is not the case

## build instructions
Use g++ to compile as it's just a single file:
```
g++ -o compiler compiler.cpp
```
And to run a .bf program use:
```
./compiler input.bf
```

## how to use bf

So let's get familiar with the syntax first.

We have only 8 keywords in BF language, here they are:
| Command | Purpose  |
|---------|---|
| `>` | Move the pointer to the right |
| `<`        |  Move the pointer to the left |
|  `+`      |  Increment value wherever pointer is |
| `- `| Decrement value wherever the pointer is |
| `.` | Output the value which is stored in current cell (where pointer is) |
| `[` | If the value at the current cell is 0 then jump to corresponding `]`. Otherwise skipped. |
| `]` | If the value at current cell is anything than 0 then jump to corresponding `[`. Otherwise skipped. |
| `,` | Input a character and store it in current cell. |

Funny enough, Brainfuck is [Turing-complete](https://en.wikipedia.org/wiki/Turing_completeness) language, which means it's theoretically capable of expressing any algorithm (program) that can be expressed with any other Turing-complete language.

To be fair, theoretical Turing-completeness requires infinite amount of memory, but my compiler that I've written in this repository (check out `compiler.cpp`) only uses 30'000 memory cells. This value can be easily increased, though.