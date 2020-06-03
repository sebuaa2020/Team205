#include "main.h"

bool delay = true;
//soundplay
ros::Publisher speak_pub;
sound_play::SoundRequest spk_msg;
// navigation
waterplus_map_tools::GetWaypointByName srvName;
ros::Publisher add_waypoint_publisher;
ros::ServiceClient get_wappoint_client;
// grab
std_msgs::String behavior_msg;
ros::Publisher behaviors_pub;
ros::Subscriber grab_res_sub;
ros::Subscriber pass_res_sub;


int main(int argc, char** argv) {
    ros::init(argc, argv, "team205");
    ros::NodeHandle n;
    // soundplay
    speak_pub = n.advertise<sound_play::SoundRequest>("/robotsound", 20);
    spk_msg.sound = sound_play::SoundRequest::SAY;
    spk_msg.command = sound_play::SoundRequest::PLAY_ONCE;
    // navigation
    add_waypoint_publisher = n.advertise<waterplus_map_tools::Waypoint>( "/waterplus/add_waypoint", 1);
    get_wappoint_client = n.serviceClient<waterplus_map_tools::GetWaypointByName>("/waterplus/get_waypoint_name");
    // grab
    behaviors_pub = n.advertise<std_msgs::String>("/wpb_home/behaviors", 30);
    grab_res_sub = n.subscribe<std_msgs::String>("/wpb_home/grab_result", 30, &GrabResultCB);
    pass_res_sub = n.subscribe<std_msgs::String>("/wpb_home/grab_result", 30, &GrabResultCB);

    // 开启socket后端
    std::thread socket_thread(runSocketServer);
    socket_thread.detach();

    // 延迟等待
    while (command == "") ;
    // 选择建图
    std::cout << "------" << std::endl;
    std::cout << command << std::endl;
    if (command == "[GOTO_INDEX_WITH_CREATING]") {
        bulidMap();
    } else {
        if (!checkMapExist()) {
            noMapException();
            exit(0);
        }
    }
    // 加载地图
    loadMap();
}