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

/**Potentionmeter-Based Arm**/
void liftPot(int power, int angle){
	if(power != 0)			//Adds ability to stop arm motor using this function
	{
		//Runs arm at specified power until it reaches desired potentiometer postition
		if(SensorValue[armPot] > angle)
		{
			while(SensorValue[armPot] > angle){
				basicLift(power);
			}
		}
		else
		{
			while(SensorValue[armPot] < angle){
				basicLift(power);
			}
		}
	}
	basicLift(0);		//Stops arm after position is reached
}
