#include "functions.c"

void redAuton() {
	resetAll(200);

	//Drive to 1st cube
	encoderDrive(100,350);
	resetDriveEncoders(400);

	//Intake
	timedIntake (-127, 1000);

	//Drive to post
	encoderDrive(100,1200);
	resetDriveEncoders(400);

	//Lift
	liftPot(100, 2600);
	wait1Msec(400);

	//Spin to post
	//basicDrive(-90, 80);
	//wait1Msec(650);
	//drive(0);
	//resetDriveEncoders(400);

	spin(305, 50);
	drive(0);
	resetDriveEncoders(400);

	//Drive back a bit
	drive(0);
	wait1Msec(100);
	drive(0);

	//Outtake
	timedIntake(127, 3000);

	//Drive back
	encoderDrive(60,-200);
	resetDriveEncoders(400);

	//Lift Down
	liftPot(127, 1000);
	wait1Msec(400);

	//Spin to cube
	basicDrive(-80, 80);
	wait1Msec(500);
	drive(0);

	//Intake
	timedIntake(127, 500);

	encoderDrive(60,-2000);
	resetDriveEncoders(400);

}

void blueAuton() {
	resetAll(200);

	//Drive to 1st cube
	encoderDrive(100,350);
	resetDriveEncoders(400);

	//Intake
	timedIntake (-127, 1000);

	//Drive to post
	encoderDrive(100,1200);
	resetDriveEncoders(400);

	//Lift
	liftPot(100, 2600);
	wait1Msec(400);

	//Spin to post
	//basicDrive(-90, 80);
	//wait1Msec(650);
	//drive(0);
	//resetDriveEncoders(400);

	spin(-305, 50);
	drive(0);
	resetDriveEncoders(400);

	//Drive back a bit
	drive(0);
	wait1Msec(100);
	drive(0);

	//Outtake
	timedIntake(127, 3000);

	//Drive back
	encoderDrive(60,-200);
	resetDriveEncoders(400);

	//Lift Down
	liftPot(127, 1000);
	wait1Msec(400);

	//Spin to cube
	basicDrive(-80, 80);
	wait1Msec(500);
	drive(0);

	//Intake
	timedIntake(127, 500);

	encoderDrive(60,-2000);
	resetDriveEncoders(400);
}

void otherAuton() {
	resetAll(200);

	//Drive back
	encoderDrive(100, -80);
	resetDriveEncoders(400);

	//Spin to post
	basicDrive(100, 100);
	wait1Msec(500);
	basicDrive(0, 0);

	//Intake position
	basicIntake(-127);
	wait1Msec(400);
	basicIntake(0);

	//Drive forward
	basicDrive(100, 100);
	wait1Msec(800);
	basicIntake(-127);
	wait1Msec(800);
	basicDrive(0, 0);
}
