void basicDrive (int leftPower, int rightPower) {
	motor[driveLeft] = leftPower;
	motor[driveRight] = rightPower;
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

void basicSkyrise (bool left, bool right) {
	SensorValue[skyriseLeft] = left;
	SensorValue[skyriseRight] = right;
}

////////////
//DRIVE////
///////////

//**Straight Drive**//
void drive(int power){

	if(power != 0)		//Adds ability to use to function to stop drive
	{
		//Compares left and right encoder values to straighten robot
		if(abs(nMotorEncoder[driveLeft]) == abs(nMotorEncoder[driveLeft])) {
			basicDrive(power, power);

			} else if(abs(nMotorEncoder[driveLeft]) < abs(nMotorEncoder[driveLeft])) {
			basicDrive(power, power - 20);

			} else {
			basicDrive(power - 20, power);
		}

		} else {
		basicDrive(0,0);
	}
}

//**Encoder Drive**//
void encoderDrive(int power, int encoderCount) {
	power = abs(power);

	int encoderAvg = (nMotorEncoder[driveRight] + nMotorEncoder[driveLeft]) / 2;

	if(encoderCount > 0) {
		while(encoderAvg < encoderCount) {
			encoderAvg = (nMotorEncoder[driveRight] + nMotorEncoder[driveLeft]) / 2;

			if(encoderAvg > encoderCount - 200) {
				drive(50);
				} else {
				drive(power);
			}
			wait1Msec(10);
		}

		} else {
		while(encoderAvg > encoderCount) {
			encoderAvg = (nMotorEncoder[driveRight] + nMotorEncoder[driveLeft]) / 2;

			if(encoderAvg < encoderCount + 200) {
				drive(-50);
				} else {
				drive(-power);
			}
			wait1Msec(10);
		}
	}

	drive(0);
}

//**Spin**//
void spin(int degrees10, int error){
	if (degrees10 > 0) {
		while(nMotorEncoder[driveLeft] < degrees10){
			motor[driveLeft] = 50;
			motor[driveRight] = -50;
		}
		drive(0);
	} else {
		while(nMotorEncoder[driveLeft] > degrees10){
			motor[driveLeft] = -50;
			motor[driveRight] = 50;
		}
		drive(0);
	}
	drive(0);
}

////////////
//Lift/////
///////////

/**Potentionmeter-Based Arm**/
void liftPot(int power, int angle) {
	power = abs(power);

	if(power != 0)			//Adds ability to stop arm motor using this function
	{
		//Runs arm at specified power until it reaches desired potentiometer postition
		if(SensorValue[armPot] > angle)
		{
			while(SensorValue[armPot] > angle){
				basicLift(-power);
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

////////////
//Intake////
///////////
void timedIntake(int power, int time) {
	motor[intake] = power;
	wait1Msec(time);
	motor[intake] = 0;
}

////////////
//Resets////
///////////
void resetDriveEncoders(int wait) {			//Clears drive encoders
	nMotorEncoder[driveLeft] = 0;
	nMotorEncoder[driveRight] = 0;
	wait1Msec(wait);
}

void resetAll(int wait){		//Stops all motors and resets all sensors
	drive(0);
	basicIntake(0);
	basicLift(0);
	resetDriveEncoders(0);
	wait1Msec(wait);
}
