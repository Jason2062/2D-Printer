# 2D-Printer
This project is a realtime writing machine, which enable user to write information remotely. This design controls the movement of the pen on the x and y axes through two stepping motors and the up and down movement of the pen through a servo motor. The [Wiki page](https://github.com/Jason2062/2D-Printer/wiki) details how to recreate the machine.<br>

![2d printer](https://github.com/Jason2062/2D-Printer/blob/master/Images/2D%20printer.jpg)


 
 # Software Design
 
# Flow Chart


The program is triggered by mouse clicks and movements. When the user moving the mouse, according to the comparison results of the x and y axis coordinates with their previous values, different threads are triggered to control the stepper motor rotating clockwise or anticlockwise and realize the x and y axis movement control of the pen. When the mouse is clicked, the Raspberry Pi switch the servo motor state to realize the pen point moving up and down. Besides, the GUI porvides the path record to facilitate the user to see the pattern printed by the 2D printer. 


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

[Doxygen documentation](http://htmlpreview.github.io/?https://github.com/Jason2062/2D-Printer/blob/master/Doxygen/html/annotated.html)
