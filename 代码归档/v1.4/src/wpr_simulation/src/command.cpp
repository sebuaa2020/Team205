#include "command.h"
using namespace std;

string command = "", name = "";

void notify(char message[]) {
    parseCommand(message);
    executeCommand();
}

void parseCommand(char message[]) {
    char split_char = ':';
    bool meet = false;
    string temp = message;
    emptyCommand();
    for (auto &c : temp) {
        if (c == split_char) {
            meet = true;
            continue;
        }
        if (meet) 
            name += c;
        else 
            command += c; 
    }
}

void executeCommand() {
    if (command == "[GOTO_INDEX_WITH_CREATING]" || command == "[GOTO_INDEX_WITHOUT_CREATING]") {
        return;
    }
    // 保存地图
	else if (command == "[BUILD_MAP_COMPLETE]") {
		storeMap();
        ROS_INFO("save map success!");
	}
    // 添加巡航点指令
	else if (command == "[ADD_NAV_POINT]") {
        ROS_INFO("add new point");
		addWaypoint(name);
        ROS_INFO("add new point success!");
	} 
    // 巡航指令
    else if (command == "[CHOSE_NAV_POINT]") {
        // 添加起点(这里有个小问题起点会不会重复？)
        addWaypoint("master");
        ROS_INFO("go to dst");
        gotoWaypoint(name);
    }
    // 抓取指令
    else if (command == "grab") {
        grab();
    }
    // 返回初始地点指令
    else if (command == "[GET_BACK_POINT]") {
        gotoWaypoint("master");
        // 删除起点
        deleteWaypoint("master");
    }
    // 物品检测
    else if (command == "[ITEM_IDENT]") {
        std::thread detect_thread(detect);
        detect_thread.detach();
    }
    // 递送指令
    else if (command == "pass") {
        pass();
    }
    else {
        noCommandException(command);
    }
    command = "";
    name = "";
}

void emptyCommand() {
    command = "";
    name = "";
}