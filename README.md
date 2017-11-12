# Extended Kalman Filter Project:

Udacity Self-Driving Car Engineer Nanodegree Program. Term 2, Project 1.


### Rubric:

The rubric followed for this project can be viewed [Here](https://review.udacity.com/#!/rubrics/748/view).


### Credit: 

Media used in this writeup are from lessons in the Udacity Self-Driving Car Engineer Nanodegree Program.
[Link To The Program](https://www.udacity.com/course/self-driving-car-engineer-nanodegree--nd013).


### Important Dependencies

* cmake >= 3.5
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
  
  
### Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make` 
   * On windows, you may need to run: `cmake .. -G "Unix Makefiles" && make`
4. Run it: `./ExtendedKF `


### Note:

This project code connects to a simulator to output its calculations, and therefore cannot show output without access to it. Example output from the simulator can be viewed below.


---

# Purpose:

This project is to demonstrate the implementation of a kalman filter on noisy radar and lidar measurements to estimate the state of a moving object. The predictions will be measured for accuracy by calculating RMSE (Root-Mean-Square Error). This is further discussed below.


---

# Using Radar And Lidar Measurements:

Radar and lidar are used in conjunction for this project to get accurate measurements of object position. Since radar and lidar have different strengths and weaknesses, using both can give us a more accurate measurement for object position than only using one or the other. 

Lidar (Light Detection and Ranging): Lidar uses infared laser beams to determine the distance from the sensor to a nearby object. Lidar swivels and projects pulses of these infared beams in the area around the sensor. Theses are then reflected off of nearby objects to create a point cloud.

Radar (Radio Dection and Ranging): Radar similarily uses pulses that reflect or "echo" off surfaces. Radar works over longer distances than lidar, but has a poorer resolution-- especially vertically. 


### Radar Vs. Lidar:

| Specification | Lidar | Radar |
|:-------------:|:-----:|:------|
| Resolution    | OK    | Bad   |
| Noise         | Bad   | Bad   |
| Velocity      | Bad   | Good  | 
| All-Weather   | Bad   | Good  | 
| Size          | Bad   | Good  |


Resolution: Lidar has an OK resolution, while radar has poor resolution. Lidar has a more focussed laser and uses a higher level of vertical scan layers to create a dense point cloud. Radar has especially poor vertical resolution.

Noise: Neither sensor is particularly good with noise. Radar can be highly reflective with certain materials or surfaces, which throws off measurements. Lidar has a relatively higher resolution-- as stated before, which can pick up too much data and introduce noise. 

Velocity: Lidar can not currently measure direct velocity, and must be calculated separately. Radar can currently measure direct velocity by the doppler effect.

All-Weather: Lidar is more susceptible to different weather conditions. The sensor must be kept clean. Radar is generally good in all weather conditions. 

Size: Lidar is bulkier and harder to integrate. Radar is smaller and can be mounted behind bumpers or other non-visible locations.


---

# Program Flow:

This program follows the flow of this chart:




TODO: TALK ABOUT THE STRUCTURE OF THE EKF AND KF ALGORITHMS, (INCLUDE DIAGRAM) AND THE PIECES OF THE EQUATIONS. 

TODO: TALK ABOUT RMSE AND HOW IT IS CALCULATED IN THE PROGRAM.

TODO: DISPLAY SIMULATOR IMAGES AND TALK ABOUT THE RMSE VALUES FOR EACH DATA SET. ALSO TALK ABOUT SIMULATOR DETAILS. WHAT THE SYMBOLS REPRESENT, ETC. 

TODO: MAKE CHARTS TO SHOW THE DIFFERENCE IN RMSE WHEN USING ONLY RADAR AND ONLY LIDAR, THEN BOTH MEASUREMENTS. 

TODO: READ LESSONS AND SEE IF MISSING ANYTHING ELSE TO TALK ABOUT.
