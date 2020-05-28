#ifndef _EXCEPTION_HANDLER_H_
#define _EXCEPTION_HANDLER_H_

# include "main.h"

void noWaypointException(std::string name); 
void noCommandException(std::string command);
void noMapException();
void unableToReachDst();

#endif