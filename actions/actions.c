/**
 * @file actions.c
 * @author your name (you@domain.com)
 * @brief Function definitions for different brainfuck actions.
 * @version 0.1
 * @date 2022-04-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#define ARRAYSIZE 300
unsigned char array[ARRAYSIZE];
unsigned char *pointer = array; /* There should only ever be one pointer to this one array. */

// >	Increment the data pointer (to point to the next cell to the right).
// <	Decrement the data pointer (to point to the next cell to the left).
// +	Increment (increase by one) the byte at the data pointer.
// -	Decrement (decrease by one) the byte at the data pointer.
// .	Output the byte at the data pointer.
// ,	Accept one byte of input, storing its value in the byte at the data pointer.
// [	If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
// ]	If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.

void movePointerRight()
{
    // printf("pointer start :>> %p\n", (void *)pointer);
    *(pointer++);
    // printf("pointer end :>> %p\n", (void *)pointer);
}

void movePointerLeft()
{
    // printf("pointer start :>> %p\n", (void *)pointer);
    *(pointer--);
    // printf("pointer end :>> %p\n", (void *)pointer);
}

void incrementCell()
{
    printf("+\n");
    (*pointer)++;
};

void decrementCell()
{
    printf("-\n");
    (*pointer)--;
};

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
