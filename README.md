[//]: # (Image References)

[image1]: ./imgs/sensorflow.PNG "Flow"
[image2]: ./imgs/onlypredict.PNG "Predict"
[image3]: ./imgs/hj.PNG "Jacobian"
[image4]: ./imgs/measurement.PNG "Measurement Update"
[image5]: ./imgs/hx.PNG "hx"
[image6]: ./imgs/rmse.PNG "RMSE"
[image7]: ./imgs/simicons.PNG "Simulator Icons"
[image8]: ./imgs/simoverview.PNG "Simulator Overview"
[image9]: ./imgs/simdata2.PNG "Simulator Dataset 2"


# Extended Kalman Filter Project:

Udacity Self-Driving Car Engineer Nanodegree Program. Term 2, Project 1.


### Rubric:

The rubric followed for this project can be viewed [Here](https://review.udacity.com/#!/rubrics/748/view).


### Credit: 

Pictures and equations referenced in this writeup are from lessons in the Udacity Self-Driving Car Engineer Nanodegree Program.
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

Noise: Neither sensor is particularly good with noise. Radar can be highly reflective with certain materials or surfaces, which throws off measurements. Lidar has a relatively higher resolution-- as stated before, which can pick up extra noise. 

Velocity: Lidar can not currently measure direct velocity, and must be calculated separately. Radar can currently measure direct velocity by the doppler effect.

All-Weather: Lidar is more susceptible to different weather conditions. The sensor must be kept clean. Radar is generally good in all weather conditions. 

Size: Lidar is bulkier and harder to integrate. Radar is smaller and can be mounted behind bumpers or other non-visible locations.


---

# Program Flow:

This program follows the flow of this chart:

![alt text][image1]


### Initialize Matrices: 
- R: measurement noise. 
- H: measurement function.

### First measurement:
- Yes: Initialize state x. Convert from polar to cartesian if a radar measurement.
       Initialize uncertainty covariance P. 
       Initialize state transition matrix F. 
       
- No: Compute elapsed time delta t. (Current - Previous) / 1000000. 

### Compute new F,Q:
- F: Computed with new delta t. 
- Q: Process covariance matrix. Computed with delta t and x and y noise.

### Predict x, P:
- Run a prediction with previously defined matrices. 

     ![alt text][image2]
     
  (u is not used for prediction step in this program as u = 0)
  
The above initialization steps can be viewed in `FusionEKF.cpp`. Prediction function in `kalman_filter.cpp`.

### State Update with Kalman Filter equation or Extended Kalman Filter equation:
- Radar: Linearize measurement function by calculating jacobian matrix Hj:

     ![alt text][image3]
     
  Run measurement update with Extended Kalman Filter equations:
  
     ![alt text][image4]
     
  Image referenced is of Kalman Filter equations. Extended Kalman Filter equation is modified to be y = z - h(x), and uses Hj in place
  of any other H. h(x) is defined as:
  
     ![alt text][image5]
     
 - Lidar: Update function run from standard Kalman Filter equations:
 
     ![alt text][image4]
      
   ^T = Tranpose.
   ^-1 = Inverse.
   
The measurement function can be found in `kalman_filter.cpp` and the CalculateJacobian() in `tools.cpp`.
   
   
 ---
 
 # RMSE (Root-Mean-Square Error):
 
 To calculate the accuracy of estimated postitions from the Kalman Filter, we use RMSE. This is calculated from the following equation:
 
 ![alt text][image6]
 
 This equation takes the difference between the estimates and the ground truth, then squares them so larger differences are weighted
 more. These squared differences are then summed, averaged, and taken the root of to get the final value.
 
 I took the final RMSE of 3 distinct simulations estimated points. One with only radar measurements, one with only lidar measurements,
 and then both measurements combined. These are the final outcomes for each distinct simulation after one full run with data set 1: 
 
 (Smaller RMSE = More accurate)
 
 | Lidar     | 
 |:---------:|
 | X: 0.1473 |
 | Y: 0.1153 | 
 |VX: 0.6383 |
 |XY: 0.5346 |
 
 | Radar     |
 |:---------:|
 | X: 0.2357 |
 | Y: 0.3110 | 
 |VX: 0.5679 |
 |XY: 0.7818 |
 
 |Radar + Lidar|
 |:-----------:|
 | X: 0.0996   |
 | Y: 0.0837   | 
 |VX: 0.4517   |
 |XY: 0.4419   |
 
 As can be seen above, lidar is the most accurate standalone measurement. As to be expected: both sensors combined has a much better
 accuracy than either on its own. My passing threshold was <= [.11, .11, 0.52, 0.52] for this project, which my sensor fusion passes. 
 
 
 ---
 
 # Simulator Details And Outcome:
 
 The simulator is a flat overhead view of a car that displays simulated radar and lidar measurements:
 
 ![alt text][image7]
 
 The red circles represent lidar measurements, blue circles are radar, and the green triangles are the estimated postitions from the
 Kalman Filter. 
 
 The simulator has two datasets to run. The first is a figure 8 line, the second is a reverse figure 8 line:
 
 Dataset 1:
 
 ![alt text][image8]
 
 As can be seen above, my estimated line is fairly accurate. My final RMSE values here are the ones discussed above in the RMSE section.
 
 Dataset 2:
 
 ![alt text][image9]
 
 
 
 
 
 
 
   
 
   
     
     
  
  
  
  
  
  
  
  
     



      
  





