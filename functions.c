void basicDrive (int leftPower, int rightPower) {
	motor[driveLeft1] = motor[driveLeft2] = leftPower;
	motor[driveRight1] = motor[driveRight2] = rightPower;
}

void driveNoStall (int leftPower, int rightPower, int stallPower) {
	if (abs(leftPower) <= stallPower) leftPower = 0;
	if (abs(rightPower) <= stallPower) rightPower = 0;
	basicDrive(leftPower, rightPower);
}

void basicLift (int power) {
	motor[liftLeft1] = motor[liftLeft2] = motor[liftRight1] = motor[liftRight2] = power;
}

void basicIntake (int power) {
	motor[intake] = power;
}