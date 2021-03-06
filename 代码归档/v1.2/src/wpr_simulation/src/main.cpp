#include "main.h"

bool delay = true;
// navigation
waterplus_map_tools::GetWaypointByName srvName;
ros::Publisher add_waypoint_publisher;
ros::ServiceClient get_wappoint_client;
// grab
std_msgs::String behavior_msg;
ros::Publisher behaviors_pub;
ros::Subscriber grab_res_sub;
ros::Subscriber pass_res_sub;


void init() {
    // 前端实现
    /*
    std::cout << "是否需要建图: Y(是) N(否)" << std::endl;
    std::string confirm = "";
    std::cin >> confirm;
    if (confirm == "Y") {
        delay = false;
        bulidMap();
    }
    delay = false;
    */ 
}


int main(int argc, char** argv) {
    ros::init(argc, argv, "team205");
    ros::NodeHandle n;
    // navigation
    add_waypoint_publisher = n.advertise<waterplus_map_tools::Waypoint>( "/waterplus/add_waypoint", 1);
    get_wappoint_client = n.serviceClient<waterplus_map_tools::GetWaypointByName>("/waterplus/get_waypoint_name");
    // grab
    behaviors_pub = n.advertise<std_msgs::String>("/wpb_home/behaviors", 30);
    grab_res_sub = n.subscribe<std_msgs::String>("/wpb_home/grab_result", 30, &GrabResultCB);
    pass_res_sub = n.subscribe<std_msgs::String>("/wpb_home/grab_result", 30, &GrabResultCB);

    // std::thread init_thread(init);
    // while(delay) {};
    std::thread command_thread(getCommand);
    ROS_INFO("environment buliding");
    loadMap();
}