#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "ex3_pkg/numbers.h"
#include "ex3_pkg/sum.h"
#include <iostream>

using namespace std;

class ROS_SUB{

	public:
		ROS_SUB();
		void topic_cb( ex3_pkg::numbersConstPtr msg );
	private:
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
		ros::Publisher _topic_pub;
};

ROS_SUB::ROS_SUB(){
	_topic_sub = _nh.subscribe("/numbers", 0, &ROS_SUB::topic_cb, this);
	_topic_pub = _nh.advertise <ex3_pkg::sum> ("sum",10);
}

void ROS_SUB::topic_cb( ex3_pkg::numbersConstPtr msg ){
	
	ex3_pkg::sum msg2;

	msg2.n1 = msg->n1;
	msg2.n2 = msg->n2;
	msg2.result = msg2.n1 + msg2.n2;
	_topic_pub.publish(msg2);
	ROS_INFO("%f + %f = %f", msg2.n1, msg2.n2, msg2.result);
}

int main(int argc, char **argv)
{
	ros::init(argc,argv, "node2");
	ROS_SUB rs;
	ros::spin();
	//return 0;
}
