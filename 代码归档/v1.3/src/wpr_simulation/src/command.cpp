#include "command.h"
using namespace std;

void getCommand() {
    cout << "输入指令：" << endl;
	string command = "empty";
	while (true) {
		cin >> command;
        // 保存图指令
		if (command == "save") {
			storeMap();
		}
        // 添加巡航点指令
		else if (command == "add") {
			string place_name = "empty";
			cin >> place_name;
            ROS_INFO("add new point");
			addWaypoint(place_name);
            ROS_INFO("add new point success!");
		} 
        // 巡航指令
        else if (command == "navigation") {
            // ui交互输入目的巡航点名字
            string dstname = "";
            cin >> dstname;
            // 添加起点(这里有个小问题起点会不会重复？)
            addWaypoint("master");
            ROS_INFO("go to dst");
            gotoWaypoint(dstname);
        }
        // 抓取指令
        else if (command == "grab") {
            grab();
        }
        // 返回初始地点指令
        else if (command == "return") {
            gotoWaypoint("master");
            // 删除起点
            deleteWaypoint("master");
        }
        // 递送指令
        else if (command == "pass") {
            pass();
        }
        else if (command == "empty") {

        }
        else if (command == "exit") {
            break;
        }
        else {
            noCommandException(command);
        }
        command = "empty";
	}
}