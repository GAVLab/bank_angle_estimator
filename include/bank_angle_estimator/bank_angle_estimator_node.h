#ifndef BANK_ANGLE_ESTIMATOR_NODE_H
#define BANK_ANGLE_ESTIMATOR_NODE_H

// ROS Includes
#include <ros/ros.h>
#include <ros/time.h>

// Boost Includes

// C++ Includes
#include <vector>
#include <math.h>
#include <cmath>

// Message Include
#include <loosely_coupled_ekf/LooselyCoupledEstimate.h>

// Eigen Package include
#include <eigen3/Eigen/Dense>

// Other Includes
#include "bank_angle_estimator.h"


class BankAngleNode
{
public:
	BankAngleNode();
	~BankAngleNode(){};

	// Subscribe to EKF to retrieve 
	ros::Subscriber ekfSub;
	void ekf_estimate_callback(const loosely_coupled_ekf::LooselyCoupledEstimate& msg);


private:
	BankAngleEstimator estimator;
};


#endif