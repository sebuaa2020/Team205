## ROS GUI
### 一、安装教程
#### 1、首先安装ros对qt pkg的支持
```bash
$ sudo apt-get install ros-kinetic-qt-create
```

```bash
$ sudo apt-get install ros-kinetic-qt-build
```
```bash
$ sudo apt-get install qtmultimedia5-dev
```
#### 2、编译
将软件包放入catkin_ws/src软件包目录下：
```bash
$ catkin_make
```
#### 3、运行
```bash
$ rosrun team205_robot team205_robot
```
### 注意事项

#### 1、运行前需要配置ROS，在.bashrc中增加

```bash
export ROS_HOSTNAME=localhost
export ROS_MASTER_URI=http://localhost:11311
```

#### 2、需要先开启roscore，或执行相应.launch文件，才能连接成功RosMaster

#### 3、运行时根据实际情况，改变对应的topic名称，订阅Ros topic