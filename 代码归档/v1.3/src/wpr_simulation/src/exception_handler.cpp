# include "exception_handler.h"

void noWaypointException(std::string name) {
    ROS_ERROR("No such a point %s", name.c_str());
    Speak("No such a point");
    return;
} 

void noCommandException(std::string command) {
    ROS_ERROR("No such a command %s", command.c_str());
    Speak("No such a command");
    return;
}

void noMapException() {
    ROS_ERROR("No map, you have to bulid map first!");
    Speak("You have to bulid map first");
    return;
}

void unableToReachDst() {
    ROS_ERROR("Unable to reach the destination!");
    Speak("Unable to reach the destination");
    return;
}