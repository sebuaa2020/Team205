#ifndef _FUNCTIONAL_H_
#define _FUNCTIONAL_H_

#include <fstream>
#include <iostream>

#include "main.h"

extern ros::Publisher speak_pub;
extern sound_play::SoundRequest spk_msg;
bool checkMapExist();
void Speak(std::string inStr);

#endif