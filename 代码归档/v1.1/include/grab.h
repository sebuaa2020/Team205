#include<main.h>

// 定义抓取操作的publisher
// behaviors_pub = n.advertise<std_msgs::String>("/wpb_home/behaviors", 30);
ros::Publisher behaviors_pub;    
// behavior_msg = "grab start" 抓取开始
// behavior_msg = "grab end"   抓取结束
// pass start, pass end 递送开始递送结束
td_msgs::String behavior_msg;    
// 订阅抓取结果 grab_res_sub = n.subscribe("/wpb_home/grab_result", 30, GrabResultCB); GrabResultCB为回调函数,自己设，参数类型为const std_msgs::String::ConstPtr
ros::Subscriber grab_res_sub;  
// 订阅递送结果 与grab_res_sub定义相同
ros::Subscriber pass_res_sub;


void GrabResultCB(const std_msgs::String::ConstPtr &msg);
void grab();
void pass();