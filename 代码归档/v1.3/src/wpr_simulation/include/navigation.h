#ifndef _NAVIGATION_H_
#define _NAVIGATION_H_

#include "main.h"

// 添加巡航点相关
// 定义publisher add_waypoint_pub
// add_waypoint_pub = n.advertise<waterplus_map_tools::Waypoint>( "/waterplus/add_waypoint", 1);
// 位置信息的数据类型为waterplus_map_tools::Waypoint
// 通过定义addNewWaypoint(string pos_name),将位置信息更新到topic
extern ros::Publisher add_waypoint_publisher;
//获取巡航点相关
// waterplus_map_tools/srv/GetWaypointByName.srv文件中储存航点信息
// 定义waterplus_map_tools::GetWaypointByName client发出request
// service应该是map_tools工具定义好的，名称为/waterplus/get_waypoint_name
// cliGetWPName = n.serviceClient<waterplus_map_tools::GetWaypointByName>("/waterplus/get_waypoint_name");
extern ros::ServiceClient get_wappoint_client;
// 定义一个service message的壳，设置巡航点的name，然后client.call(srvname)
// call 返回的结果放在 srvname的壳中
extern waterplus_map_tools::GetWaypointByName srvName;
// 得到srvname后设置move_base_msgs::MoveBaseGoal goal;
// 声明一个 MoveBaseClient 对象 ac,用来调用和主管监控导航功能的服务
// MoveBaseClient ac("move_base", true);   
// 向move_base发送巡航点，wpb_home_curise.cpp
// ac.sendGoal(goal)
// 向巡航点运动相关


void addWaypoint(std::string name);
bool getWaypoint(std::string name);
void gotoWaypoint(std::string name);
void gobackStartpoint();
void deleteWaypoint(std::string name);

#endif