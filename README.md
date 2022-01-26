# Udacity_Robo_SW_ND_P2_Go_Chase_It
Design and build a mobile robot inside Gazebo, house it in the World, Then write C++ Nodes in ROS to chase white balls.



## Directory Structure

    .RoboND-Go-Chase-It-Project-P2                          # Go Chase It Project
    ├── my_robot                       # my_robot package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── robot_description.launch
    │   │   ├── world.launch
    │   ├── meshes                     # meshes folder for sensors
    │   │   ├── hokuyo.dae
    │   ├── urdf                       # urdf folder for xarco files
    │   │   ├── my_robot.gazebo
    │   │   ├── my_robot.xacro
    │   ├── world                      # world folder for world files
    │   │   ├── <yourworld>.world
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info
    ├── ball_chaser                    # ball_chaser package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── ball_chaser.launch
    │   ├── src                        # source folder for C++ scripts
    │   │   ├── drive_bot.cpp
    │   │   ├── process_images.cpp
    │   ├── srv                        # service folder for ROS services
    │   │   ├── DriveToTarget.srv
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info                  
    └──                              

**Create the my_robot Package**

Create and initialize a catkin_ws Feel free to skip if you already have a catkin_ws.

$ mkdir -p /home/workspace/catkin_ws/src

$ cd /home/workspace/catkin_ws/src

$ catkin_init_workspace

Clone or Download This Project Under the /home/workspace/catkin_ws/src

$ cd /home/workspace/catkin_ws/src

$ git clone  myrobot

Build Package

Now that you’ve included specific instructions for your process_image.cpp code in CMakeLists.txt, compile it with:

$ cd /home/workspace/catkin_ws/
$ catkin_make
Test process_image
To test if the code you just wrote is working as expected, first launch the robot inside your world and then run both the drive_bot and process_image nodes.

1- Launch the robot inside your world

This can be done by launching the world.launch file:

$ cd /home/workspace/catkin_ws/
$ source devel/setup.bash
$ roslaunch my_robot world.launch

2- Run drive_bot and process_image (new terminal)

This can be done by executing ball_chaser.launch:

$ cd /home/workspace/catkin_ws/
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
