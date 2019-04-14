# 2D-Printer

![2d printer](https://github.com/Jason2062/2D-Printer/blob/master/Images/2D%20printer.jpg)


 
 # Software Design
 
# Flow Chart

GUI程序由鼠标的点击和移动触发。用户控制鼠标移动时，根据x，y轴坐标与先前数值的对比结果，开启不同线程工作，控制电机运转，实现对笔的xy轴控制。当鼠标点击时，切换伺服电机状态，实现笔尖收起和释放（实现笔尖上下控制）

![flow chart](https://github.com/Jason2062/2D-Printer/blob/master/Images/Flow%20chart.png)


# Required Package
## How to install QT5 and QT Creator
```
sudo apt-get update
sudo apt-get upgrade 

//Install QT5 

sudo apt-get install qt5-default

//Install QT creator

sudo apt-get install qtcreator
```
## How to install wiringPi

```
git clone git://git.drogon.net/wiringPi

cd wiringPi
./build

Type “gpio -v” to test

Type “gpio readall’ to check pin information
```

# Documentation

