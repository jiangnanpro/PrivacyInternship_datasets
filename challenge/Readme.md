# Tic-tac-toe AI Boolean circuit generator.

This program generate a Boolean circuit for the following Boolean function:

```c
void play (const int x[9], const int o[9], int new_o[9]) {...}
```
The generated Boolean circuit only contains **NOT**, **AND** and **OR** ports, with 13652 logical gates in total:
- 5596 NOT_gates;
- 7616 AND_gates;
- 440  OR_gates.


In this program, the basic part of the game and the computer AI were implemented in **board.c**. The AI was designed by using **Minimax** algorithm.

The **logic.c** file contains the functions which were implemented for generating the truth table by parsing resursively all the possibilities. The generated truth table was written in the file **truth_table** with PLA format, then it was minimized by applying [**Espresso-logic-minimizer**](https://github.com/classabbyamp/espresso-logic). The minimized truth table was written in the file **truth_table_minimized**.


## How to run

Enter '*make*' to compile this program, then enter '*./generator*' to run the file compiled. You can then enter '*make clean*' to remove all the unnessasery files.

After running process, this program will generate a program file named **boolean_function.c**  in the **'Test'** directory.

## How to test the Boolean function
To compile and test the Boolean function, please locate the ternimal in the **'Test'** directory then enter the following commands:

```
gcc -o test main.c boolean_function.c boolean_function.h
./test

```

This will display one possible complete game flow with the Boolean function. You can also try other cases by modifying the code in **main.c** (located in Test directory).


