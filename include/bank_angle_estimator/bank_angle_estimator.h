#ifndef BANK_ANGLE_ESTIMATOR_H
#define BANK_ANGLE_ESTIMATOR_H

// ROS Includes
#include <ros/ros.h>
#include <ros/time.h>

// Eigen Package Include
#include <eigen3/Eigen/Dense>

// Message Include
#include <bank_angle_estimator/Bank_Estimate.h>

// Define PI and gpsPI
#ifndef PI
#define PI 3.14159265358979
#endif

class BankAngleEstimator
{
public:
	BankAngleEstimator();
	~BankAngleEstimator(){};

	void estimation();

	ros::Publisher rollRelPub;

	struct parameters
	{
		double Krr;
	};
	parameters prms;

	double ay; // Lateral acceleration [m/s^2]
	double roll; // Euler Roll [rad]

private:

	double rollS; // Roll due to suspension
	double rollR; // Relative Roll/Roll due to road bank
};

#endif