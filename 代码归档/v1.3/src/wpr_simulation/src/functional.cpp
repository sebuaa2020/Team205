# include "functional.h" 
using namespace std;

bool checkMapExist() {
    // 改成你自己的工作区map路径
    string file_path = "/home/lxy/catkin_ws2/src/wpr_simulation/maps/map.yaml";
    fstream _file;
    _file.open(file_path, ios::in);
    if(!_file) 
        return false;
    return true;
}

// 语音说话
void Speak(std::string inStr)
{
    spk_msg.arg = inStr;
    speak_pub.publish(spk_msg);
}
