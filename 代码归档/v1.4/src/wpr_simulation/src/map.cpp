#include<map.h>

void bulidMap() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	system("roslaunch wpr_simulation wpb_gmapping.launch");
}

void storeMap() {
    system("rosrun map_server map_saver -f map");
    system("cp /home/lxy/catkin_ws2/map.pgm /home/lxy/catkin_ws2/src/wpr_simulation/maps/");
    system("cp /home/lxy/catkin_ws2/map.yaml /home/lxy/catkin_ws2/src/wpr_simulation/maps/");
	ROS_INFO("Map saved successfully");
}

void loadMap() {
    system("roslaunch wpr_simulation add_waypoint.launch");
}