#include<command.h>

void getCommand() {
	string command = "empty";
	while (command != "exit") {
		cin >> command;
        // 保存图指令
		if (command == ) {
			saveMap();
		}
        // 建图完毕
        if (command == ) {
            // 关闭建图roslaunch
            system("");
            // 打开图
            
        }
        // 添加巡航点指令
		if (command == ) {
			string place_name = "empty";
			cin >> place_name;
			addWaypoint(place_name);
		} 
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