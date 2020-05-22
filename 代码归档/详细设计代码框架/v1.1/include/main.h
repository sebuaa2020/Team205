#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <grab.h>
#include <map.h>
#include <command.h>
#include <navigation.h>
#include <iostream>
#include <main.h>
#include <thread>
using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient

// navigation.h
extern ros::Publisher add_waypoint_publisher;
extern ros::ServiceClient get_wappoint_client;
extern waterplus_map_tools::GetWaypointByName srvName;
extern MoveBaseClient MoveBaseClient;

// grab.h
extern ros::Publisher behaviors_pub;  
extern ros::Subscriber grab_res_sub;  
extern ros::Subscriber pass_res_sub; 
