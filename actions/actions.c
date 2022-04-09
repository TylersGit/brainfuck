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

int loopFlag = 0; /* Is a loop currently being registered */

// ,	Accept one byte of input, storing its value in the byte at the data pointer.

void movePointerRight()
{
    *(pointer++);
}

void movePointerLeft()
{
    *(pointer--);
}

void incrementCell()
{
    (*pointer)++;
};

void decrementCell()
{
    (*pointer)--;
};

void outputCell()
{
    // Do not output a new line.
    // New line characters must be output explicitely by the brainfuck instruction strip.
    printf("%c", *pointer);
}

// '['	If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ']' command.
void loopStarter(FILE *strip)
{
    char testCharacter;

    // Check if the current byte is equal to 0.
    if (*pointer == 0)
    {
        while (1)
        {
            // Skip until the next ']' char
            testCharacter = fgetc(strip);
            if (testCharacter == ']')
            {
                break;
            }
        }
    }
}

// ]	If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.
void loopEnder(FILE *strip)
{
    char testCharacter;

    // Check if byte is a non zero character
    if (*pointer != 0)
    {
        while (1)
        {
            // Place the cursor two characters back.
            // This makes fgetc get the previous character in the file.
            fseek(strip, -2, SEEK_CUR);
            testCharacter = fgetc(strip);
            if (testCharacter == '[')
            {
                break;
            }
        }
    }
}

void performAction(char character, FILE *instructionStrip)
{
    switch (character)
    {
    case '>':
        movePointerRight();
        break;
    case '<':
        movePointerLeft();
        break;
    case '+':
        incrementCell();
        break;
    case '-':
        decrementCell();
        break;
    case '.':
        outputCell();
        break;
    case '[':
        loopStarter(instructionStrip);
        break;
    case ']':
        loopEnder(instructionStrip);
        break;
    case '\n':
        break;
    default:
        printf("%c Instruction skipped\n", character);
        break;
    }
}
