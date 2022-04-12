#include <stdio.h>
#include <stdlib.h>

FILE *instructionsPointer;
FILE *outputPointer;
char instruction;

int main(int argc, char *argv[])
{

    instructionsPointer = fopen("instructions.txt", "r");
    outputPointer = fopen("Compiled.c", "w");

    // Make sure that the instruction file exists.
    if (instructionsPointer == NULL)
    {
        fprintf(stderr, "instructions.txt not found.");
        exit(1);
    }

    fprintf(outputPointer, "#include <stdio.h>\n\n");
    fprintf(outputPointer, "char array[30000];\n");
    fprintf(outputPointer, "char *pointer = array;\n");
    fprintf(outputPointer, "int main(){\n");

    while (1)
    {
        instruction = fgetc(instructionsPointer);
        if (instruction == EOF)
        {
            break;
        }
        else
        {

            switch (instruction)
            {
            case '<':
                fprintf(outputPointer, "*(pointer--);\n");
                break;
            case '>':
                fprintf(outputPointer, "*(pointer++);\n");
                break;
            case '+':
                fprintf(outputPointer, "(*pointer)++;\n");
                break;
            case '-':
                fprintf(outputPointer, "(*pointer)--;\n");
                break;
            case '.':
                fprintf(outputPointer, "printf(\"%%c\", *pointer);\n");
                break;
            case ',':
                fprintf(outputPointer, "*pointer = getchar();\n");
                break;
            case '[':
                fprintf(outputPointer, "while (*pointer){\n");
                break;
            case ']':
                fprintf(outputPointer, "}\n");
                break;

            default:
                break;
                printf("skip\n");
            }
        }
    }

    fprintf(outputPointer, "}\n");

    fclose(instructionsPointer);
    fclose(outputPointer);

    return 0;
}