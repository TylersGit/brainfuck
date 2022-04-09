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
#include <stdlib.h>
#include "actions/actions.h"

char instruction;

int main(int argc, char *argv[])
{
    FILE *instructionsStrip = fopen("HelloWorld.txt", "r");

    // Check that the instruction file exists
    if (instructionsStrip == NULL)
    {
        fprintf(stderr, "Instructions file not found.\n");
        exit(1);
    }

    printf("pointer :>> %p\n", (void *)pointer);

    while (1)
    {
        instruction = fgetc(instructionsStrip);
        if (instruction != EOF)
        {
            performAction(instruction, instructionsStrip);
        }
        else
        {
            break;
        }
    }

    fclose(instructionsStrip);
    return 0;
}