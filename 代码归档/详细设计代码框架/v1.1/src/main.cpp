#include<main.h>

void init() {
    // 前端实现
    cout << "是否需要建图: Y(是) N(否)" << endl;
    if ("Y") {
        buildMap();
    } 
    load_map();
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "team205");
    ros::NodeHandle n;
    // navigation
    add_waypoint_publisher = n.advertise<waterplus_map_tools::Waypoint>( "/waterplus/add_waypoint", 1);
    get_wappoint_client = n.serviceClient<waterplus_map_tools::GetWaypointByName>("/waterplus/get_waypoint_name");
    // grab
    behaviors_pub = n.advertise<std_msgs::String>("/wpb_home/behaviors", 30);
    grab_res_sub = n.subscribe("/wpb_home/grab_result", 30, GrabResultCB);
    pass_res_sub = n.subscribe("/wpb_home/grab_result", 30, GrabResultCB);

    std::thread init_thread(init);
    std::thread command_thread(getCommand);
    system("roslaunch wpr_simulation wpb_simple.launch");
}