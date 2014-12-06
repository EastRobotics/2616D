#include "functions.c"

void ourAutonomous() {
	//Go back
	basicDrive(-80, -80);
	wait1Msec(500);
	basicDrive(0, 0);
	wait1Msec(500);

	//Spin to goal
	basicDrive(-50, 50);
	wait1Msec(600);
	basicDrive(0, 0);
	wait1Msec(500);

	//Lift up
	basicLift(100);
	wait1Msec(750);
	basicLift(20);
	wait1Msec(500);

	//Drive to goal
	// basicDrive(80, 80);
	// wait1Msec(500);
	// basicDrive(0, 0);
	// wait1Msec(500);

	//Outtake
	basicIntake(127);
	wait1Msec(1000);

	//Drive back
	basicDrive(-80, -80);
	wait1Msec(500);
	basicDrive(0, 0);
}