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
char array[ARRAYSIZE];
char *pointer = array; /* There should only ever be one pointer to this one array. */

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

void incrementCell()
{
    printf("+\n");
};

void decrementCell()
{
    printf("-\n");
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
