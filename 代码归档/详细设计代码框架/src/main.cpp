#include<main.h>

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

    while (ros::ok) {
        // command为ui交互
        // 建图指令
        if (command == ) {
            buildMap();
        }
        // 保存图指令
        if (command == ) {
            storeMap();
        }
        // 添加巡航点指令
        if (command == ) {
            // ui交互输入巡航点名字
            placename = "";
            addWaypoint(placename);
        }
        // 巡航指令
        if (command == ) {
            // ui交互输入目的巡航点名字
            dstname = "";
            // 添加起点(这里有个小问题起点会不会重复？)
            addWaypoint("master");
            gotoWaypoint(dstname);
        }
        // 抓取指令
        if (command == ) {
            grab();
        }
        // 返回初始地点指令
        if (command == ) {
            gotoWaypoint("master");
            // 删除起点
            deleteWaypoint("master");
        }
        // 递送指令
        if (command ==) {
            pass();
        }
    }
}