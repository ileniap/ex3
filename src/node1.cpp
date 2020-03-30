#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "ex3_pkg/numbers.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char **argv){
	ros::init(argc, argv, "node1");
	ros::NodeHandle nh;
	ros::Publisher topic_pub = nh.advertise <ex3_pkg::numbers> ("/numbers",10);
	srand(time(NULL));
	ros::Rate rate(10);
	
	while(ros::ok()){
		
		ex3_pkg::numbers msg;

		float num1 = rand()%50+1;			//generazione numeri tra 1 e 50
		float num2 = rand()%50+1;;
		
		msg.n1 = num1;
		msg.n2 = num2;
		topic_pub.publish(msg);
		ROS_INFO("Random numbers: %f and %f",msg.n1,msg.n2);
		
		rate.sleep();
		
	}
	return 0;
}





