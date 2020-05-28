#include "grab.h"


void GrabResultCB(const std_msgs::String::ConstPtr& msg)
{
    // ROS_WARN("[GrabResultCB] %s",msg->data.c_str());
    // 抓取结果，怎么判断，并执行相应的操作
    // 执行成功怎么办，执行失败怎么办
}

void grab() {
    // 开始抓取
    behavior_msg.data = "grab start";
    behaviors_pub.publish(behavior_msg);
}


void pass() {
    // 开始传递
    behavior_msg.data = "pass start";
    behaviors_pub.publish(behavior_msg);
}