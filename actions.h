/**
 * @file actions.h
 * @author your name (you@domain.com)
 * @brief Contains actions for each symbol of the brainfuck language.
 * @version 0.1
 * @date 2022-04-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ACTIONS_H
#define ACTIONS_H

#define ARRAYSIZE 300

extern char *pointer; /* There should only ever be one pointer to this one array. */

#endif // ACTIONS_H

extern void movePointerRight();

extern void movePointerLeft();

extern void performAction(char character);

extern void incrementCell();

extern void decrementCell();
