## Project Monty
### Description 
 This is a program built to interpret Monty-like scripted files according to operation codes provided to us in the project.

### Examples

Format for user to write in "testfile.m": `opcode argument`

NOTE: No more than one instruction per line is allowed, there can however be as many spaces, new lines or tabs before or after the instruction.

### Allowable opcodes and what they do

|Opcode |Functionality |
|--------|--------|
|    Push    |    Add element to the 'top' of stack and 'end' of queue    |
|    Pop    |    Remove element from 'top' of stack and 'end' of queue   |
|    Pall    |    Print every member of the structure    |
|    Pint    |    Prints the member value at the top of stack   |
|    Swap   |    Swaps the order of the 1st and 2nd elements in stack    |
|    Add    |    Add top two member values   |
|    Sub    |    Subtract the top element from the 2nd top element   |
|    Div    |    Divide the 2nd element by the top element   |
|    Mul    |    Multiply the top two elements of the stack    |
|    Mod    |    The remainder when the 2nd element is divided by the top element   |
|    Comment    |   There is the ability to parse comments found in bytecode ->'#'    |
|    Nop    |    Opcode should do nothing   |

#### Examples

`push 1`

`push 2`

`push 3`

`pall`

`$ ./montyfile opcodetestfile.m`

`3`

`2`

`1`

`$`

<hr>

`$ cat opcodetestfile.m`

`push 1`

`push 2`

`push 3`

`pall`

`rotl`

`pall`

`$ ./montyfile opcodetestfile.m`

`3`

`2`

`1`

`2`

`1`

`3`

<hr>

### AUTHOR

- Kevin Munoz - kevinmunozb04@gmail.com
