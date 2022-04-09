/**
 * @file brainfuck.c
 * @author Tyler Jordan
 * @brief An interpreter for the brainfuck language, created by Urban Müller.
 * @version 0.1
 * @date 2022-04-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

// >	Increment the data pointer (to point to the next cell to the right).
// <	Decrement the data pointer (to point to the next cell to the left).
// +	Increment (increase by one) the byte at the data pointer.
// -	Decrement (decrease by one) the byte at the data pointer.
// .	Output the byte at the data pointer.
// ,	Accept one byte of input, storing its value in the byte at the data pointer.
// [	If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
// ]	If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.

#define ARRAYSIZE 300

char array[ARRAYSIZE];
char *pointer = array; /* There should only ever be one pointer to this one array. */

char instructions[] = {'>', '+', '>', '+', '<', '-', '-'}; /* Instruction strip */

void movePointerRight()
{
    printf("pointer start :>> %p\n", (void *)pointer);
    *(pointer++);
    printf("pointer end :>> %p\n", (void *)pointer);
}

void movePointerLeft()
{
    printf("pointer start :>> %p\n", (void *)pointer);
    *(pointer--);
    printf("pointer end :>> %p\n", (void *)pointer);
}

void performAction(char character)
{
    switch (character)
    {
    case '>':
        movePointerRight();
        printf("Right\n");
        break;
    case '<':
        movePointerLeft();
        printf("Left\n");
        break;
    case '+':
        incrementCell();
        break;
    case '-':
        decrementCell();
        break;
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    printf("pointer :>> %p\n", (void *)pointer);
    printf(" :>> %d %d %d \n", *pointer, *(pointer + 1), *(pointer + 2));

    for (int instruction = 0; instruction < sizeof(instructions) / sizeof(*instructions); instruction++)
    {
        performAction(instructions[instruction]);
        printf(" :>> %d %d %d \n", *pointer, *(pointer + 1), *(pointer + 2));
    }

    return 0;
}