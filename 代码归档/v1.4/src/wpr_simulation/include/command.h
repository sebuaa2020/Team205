#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "main.h"

void notify(char message[]);
void parseCommand(char message[]);
void executeCommand();
void emptyCommand();

extern std::string command;

#endif