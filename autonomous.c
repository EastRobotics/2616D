#include "functions.c"

void ourAutonomous() {
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

	// //*******AUTON*******//

	// //Pneumatics 
	// SensorValue[skyriseRight] = SensorValue[skyriseLeft] = 1; 

	// //Drive Back
	// basicDrive(-100, -100);
	// wait1Msec(500);
	// basicDrive(0, 0);
	// wait1Msec(500);

	// //Turn
	// basicDrive(80, -80);
	// wait1Msec(300);
	// basicDrive(0, 0);

	// //Lift
	// basicLift(100);
	// wait1Msec(400);
	// basicLift(0);

	// //Drive forward
	// basicDrive(70, 70);
	// wait1Msec(70);
	// basicDrive(0, 0);
	// wait1Msec(500);

	// //Outtake
	// basicIntake(100);
	// wait1Msec(1000);

	// //Drive back
	// basicDrive(-100, -100);
	// wait1Msec(500);
	// basicDrive(0, 0);
	// wait1Msec(500);

	// //Turn
	// basicDrive(-100, 100);
	// wait1Msec(2000);
	// basicDrive(0, 0);

	// //Return
	// basicDrive(100, 100);
	// wait1Msec(700);
	// basicDrive(0, 0);
	// wait1Msec(200);

	// //Outtake
	// basicIntake(127);
	// wait1Msec(1000);
	// basicIntake(0);

	// //Drive back
	// basicDrive(-100, -100);
	// wait1Msec(500);
	// basicDrive(0, 0);


}