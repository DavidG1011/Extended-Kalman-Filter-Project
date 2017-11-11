## Extended Kalman Filter Project:

Udacity Self-Driving Car Engineer Nanodegree Program. Term 2, Project 1.

The rubric followed for this project can be viewed [Here](https://review.udacity.com/#!/rubrics/748/view). 

---

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

## Purpose:


This project is to demonstrate the implementation of a kalman filter on noisy radar and lidar measurements to estimate the state of a moving object. The predictions will be measured for accuracy by calculating RMSE (Root-Mean-Square Error). This is further discussed below.

---

TODO: EXPLAIN RADAR AND LIDAR STRENGTHS AND WEAKNESSES AND HOW THEY CAN BE COMBINED TO CREATE A CLEAN OUTCOME. TALK ABOUT IMPLEMENTATIONS OF KF AND EKF FOR THE SPECIFIC DATA SETS. 

TODO: TALK ABOUT FLOW OR PROGRAM AND USE THAT FLOWCHART FROM THE LESSONS.

TODO: TALK ABOUT THE STRUCTURE OF THE EKF AND KF ALGORITHMS, (INCLUDE DIAGRAM) AND THE PIECES OF THE EQUATIONS. 

TODO: TALK ABOUT RMSE AND HOW IT IS CALCULATED IN THE PROGRAM.

TODO: DISPLAY SIMULATOR IMAGES AND TALK ABOUT THE RMSE VALUES FOR EACH DATA SET. ALSO TALK ABOUT SIMULATOR DETAILS. WHAT THE SYMBOLS REPRESENT, ETC. 

TODO: MAKE CHARTS TO SHOW THE DIFFERENCE IN RMSE WHEN USING ONLY RADAR AND ONLY LIDAR, THEN BOTH MEASUREMENTS. 

TODO: READ LESSONS AND SEE IF MISSING ANYTHING ELSE TO TALK ABOUT.
