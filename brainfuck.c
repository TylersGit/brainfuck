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
#include "actions/actions.h"

char instructions[] = {'>', '+', '<', '-', '-', '+', '+'}; /* Instruction strip */

int main(int argc, char *argv[])
{
    printf("pointer :>> %p\n", (void *)pointer);

    for (int instruction = 0; instruction < sizeof(instructions) / sizeof(*instructions); instruction++)
    {
        performAction(instructions[instruction]);
        printf(" :>> %d %d %d \n", *array, *(array + 1), *(array + 2));
    }

    return 0;
}