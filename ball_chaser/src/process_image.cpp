#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    if (!client.call(srv))
        ROS_ERROR("Failed to call service command robot");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;

    int img_height = img.height;
    int img_width = img.step;
    int max_left = img_width/3;
    int max_middle = img_width*2/3;

    int left_white_pixels = 0;
    int middle_white_pixels = 0;
    int right_white_pixels = 0;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    
    for (unsigned int i=0;i<img_width*img_height;i+=3){
      int column = i % img_width ;
      if ( (img.data[i] == white_pixel)  && (img.data[i+1] == white_pixel) && (img.data[i+2] == white_pixel) ){    // Then, identify if this pixel falls in the left, mid, or right side of the image
        if (column <= max_left)                                         left_white_pixels +=1;                       
        else if ( (column > max_left) && (column <= max_middle) )       middle_white_pixels +=1;
        else                                                            right_white_pixels +=1;

       }
    }

    // Depending on the white ball position, call the drive_bot function and pass velocities to it   
    if ((left_white_pixels > middle_white_pixels) && (left_white_pixels > right_white_pixels)) 
    drive_robot(0,0.5); //turn left
    else if (right_white_pixels > middle_white_pixels) 
    drive_robot(0,-0.5); // turn right
    else if (middle_white_pixels > 0) 
    drive_robot(0.1,0.0); //drive straight
    else 
    drive_robot(0.0,0.0);   // Request a stop when there's no white ball seen by the camera
}



int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
