#include<map.h>

void bulidMap() {
    system("roslaunch wpr_simulation wpb_gmapping.launch");
}

void storeMap() {
    system("rosrun map_server map_saver -f map");
    system("cp /home/lxy/demo2_ws/map.pgm /home/lxy/demo2_ws/src/wpr_simulation/maps/");
    system("cp /home/lxy/demo2_ws/map.yaml /home/lxy/demo2_ws/src/wpr_simulation/maps/");
    system("");
}

void getMap() {

}