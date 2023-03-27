
#include "ros/ros.h" 
#include "SINWAVE_PUB_SUB/my_msg.h"  
#include <iostream>
#include "cmath"

using namespace std;

float AMP=0;
float PER=1;

int main(int argc, char **argv) {

if(argc>=2){
	AMP=atof(argv[1]);
	}
if(argc>=3){
	PER=atof(argv[2]);
	}
	
		ros::init(argc, argv,"SINWAVE_PUB");
	
		ros::NodeHandle N;
		ros::Publisher P;
		
		P= N.advertise< SINWAVE_PUB_SUB::my_msg >("/my_msg", 1);

	ros::Rate rate(10);

	SINWAVE_PUB_SUB::my_msg msg; 

	msg.Amplitude = AMP;
	msg.Period = PER;

	double s=0;

	while ( ros::ok() ) {

		//s = ros::Time::now().toSec();
		msg.Value=AMP*sin(2*M_PI*s/(PER));
		s+=0.1;
		
		ROS_INFO("AMPLITUDE: %f",msg.Amplitude); 
		ROS_INFO("PERIOD: %f",msg.Period); 
		ROS_INFO("VALUE: %f",msg.Value); 

		P.publish(msg);
		
		rate.sleep();
	}
	
	return 0;
}
