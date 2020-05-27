#include "navigation.h"
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void addWaypoint(std::string name) {
    // 源码部分
    // 监听器
    tf::TransformListener listener;
    // 变换关系
    tf::StampedTransform transform;  //雷达到机器人的静态变换
    ROS_INFO("1");
    try
    {
        // 等待几秒，等待broadcaster发送transform
        listener.waitForTransform("/map","/base_footprint",  ros::Time(0), ros::Duration(10.0) );
        ROS_INFO("2");
        // base_footprint->map
        listener.lookupTransform("/map","/base_footprint", ros::Time(0), transform);
    }
    catch (tf::TransformException &ex) 
    {
        ROS_ERROR("[lookupTransform] %s",ex.what());
        return;
    }
    ROS_INFO("3");
    float tx = transform.getOrigin().x();
    float ty = transform.getOrigin().y();
    tf::Stamped<tf::Pose> p = tf::Stamped<tf::Pose>(tf::Pose(transform.getRotation() , tf::Point(tx, ty, 0.0)), ros::Time::now(), "map");
    ROS_INFO("4");
    geometry_msgs::PoseStamped robot_pos;
    tf::poseStampedTFToMsg(p, robot_pos);
    ROS_INFO("5");

    // 新建巡航点并publish
    waterplus_map_tools::Waypoint new_waypoint;
    new_waypoint.name = name;
    new_waypoint.pose = robot_pos.pose;
    add_waypoint_publisher.publish(new_waypoint);
}

void getWaypoint(std::string name) {
    ROS_INFO("get point information");
    srvName.request.name = name;
    get_wappoint_client.call(srvName);
}

void gotoWaypoint(std::string name) {
    getWaypoint(name);
    ROS_INFO("Will travel to %s", name);
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose = srvName.response.pose;
    MoveBaseClient ac("move_base", true);
    while(!ac.waitForServer(ros::Duration(5.0)))
    {
        if(!ros::ok())
            return;
        ROS_INFO("Waiting for the move_base action server to come up");
    }
    ac.sendGoal(goal);
    ac.waitForResult();
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Arrived at Waypoint %s", name);
    else
        ROS_INFO("The base failed to move forward 1 meter for some reason");
}


void gobackStartpoint() {
    std::string dstname = "master";
    gotoWaypoint(dstname);
}

void deleteWaypoint(std::string name) {

}