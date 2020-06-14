import os
import sys
import time
import subprocess
import datetime


#读入测试输入
with open('test_pattern.txt', 'r') as f:
    result = f.readlines()

#启动测试程序
strss = 'rosrun wprsimulation main'
obj = subprocess.Popen(strss,  stdin= subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
time.sleep(2)

#重定向输入
sign = 0
count = 0
for i in result:
    i = i.strip('\r\n')
    if(count == 0):
        if (i == 'ID1_1'):
            # 读入建图指令
            strss = 'Y\n'
            #print(strss)
            obj.stdin.write(strss.encode())
            sign = 0
        else:
            strss = 'N\n'
            #print(strss)
            obj.stdin.write(strss.encode())
            sign = 0

    if (i == 'ID1_2'):
        #读入保存地图指令
        strss = 'save\n'
        # print(strss)
        obj.stdin.write(strss.encode())
        sign = 0
    elif (i == 'ID2_1'):
        #添加巡航点
        strss = 'add\n'
        # print(strss)
        obj.stdin.write(strss.encode())
        sign = 1
    elif (i == 'ID2_2'):
        #机器人根据指定点导航
        strss = 'navigation\n'
        # print(strss)
        obj.stdin.write(strss.encode())
        sign = 2
    elif (i == 'ID2_3'):
        #机器人返回初始地点
        strss = 'return\n'
        obj.stdin.write(strss.encode())
        sign = 0
    elif (i == 'ID3_1'):
        #机器人识别物体
        strss = 'grab\n'
        # print(strss)
        obj.stdin.write(strss.encode())
        sign = 0
    elif (i == 'ID4_1'):
        #接受用户指令
        strss = 'past\n'
        # print(strss)
        obj.stdin.write(strss.encode())
        # r = os.popen(strss)
        sign = 0
    elif (sign != 0):
        strss = i + '\n'
        # print(strss)
        obj.stdin.write(strss.encode())
        sign = 0


    time.sleep(2)
    count = count + 1


obj.stdin.close()
info = obj.stdout.read()
obj.stdout.close()
with open('test_result.txt', 'a') as file:  # 'a'表示append,即在原来文件内容后继续写数据（不清楚原有数据）
    now = str(datetime.datetime.now())
    if(info):
        file.write(now + ':' + info.decode())
    else:
        file.write(now + ':' + '  succeed\n')