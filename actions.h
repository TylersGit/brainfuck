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

void movePointerRight();

void movePointerLeft();

void performAction(char character);

void incrementCell();

void decrementCell();

#endif // ACTIONS_H