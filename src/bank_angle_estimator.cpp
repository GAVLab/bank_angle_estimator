#include "bank_angle_estimator.h"

BankAngleEstimator::BankAngleEstimator()
{}

void BankAngleEstimator::estimation()
{
	rollS = prms.Krr * ay;
	rollR = (roll - rollS)*180/PI;

	bank_angle_estimator::Bank_Estimate rollRelative;

	rollRelative.header.stamp = ros::Time::now();
	rollRelative.relative_roll = rollR;

	rollRelPub.publish(rollRelative);
}