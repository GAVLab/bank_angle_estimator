#include "bank_angle_estimator_node.h"

BankAngleNode::BankAngleNode() 
{
	// Create Node Handles
	ros::NodeHandle nh;
	ros::NodeHandle nhPvt("~");

	// Parameter Assignment from Launch file
	if(
		!nhPvt.getParam("Roll_Rate_Stiffness", estimator.prms.Krr))
	{
		ROS_ERROR("Could not get all Bank Angle Estimator Parameters");
	}

	ekfSub = nh.subscribe("EKF/estimate", 10, &BankAngleNode::ekf_estimate_callback, this);

	estimator.rollRelPub = nh.advertise<bank_angle_estimator::Bank_Estimate>("bank_angle_estimator_node/roll_relative",10);
}

void BankAngleNode::ekf_estimate_callback(const loosely_coupled_ekf::LooselyCoupledEstimate& msg)
{
	estimator.roll = msg.state.roll;
	estimator.ay = msg.inputs.ay;

	estimator.estimation();
}

int main(int argc, char **argv)
{
    // Initialize ROS node
	ros::init(argc, argv, "bank_angle_estimator_node");

	BankAngleNode node;

	ros::spin();
	return 0;
}