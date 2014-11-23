#include "functions.c"

void controller() {
	bool slowDrive = false;

	while(true) {

		//Drive
		if (vexRT[Btn8RXmtr2]) slowDrive = true;
		else if (vexRT[Btn8DXmtr2]) slowDrive = true;

		driveNoStall(
			slowDrive ? (vexRT[Ch3] / 2) : vexRT[Ch3],
			slowDrive ? (vexRT[Ch2] / 2) : vexRT[Ch2],
			20);

		//Lift
		if (vexRT[Btn6U]) basicLift(127);
		else if (vexRT[Btn6D]) basicLift(-127);
		else {
			if (vexRT[Btn6UXmtr2]) basicLift(127);
			else if (vexRT[Btn6DXmtr2]) basicLift(-127); 
			else basicLift(0);
		}

		//Intake
		if (vexRT[Btn5U]) basicIntake(127);
		else if (vexRT[Btn5D]) basicIntake(-127);
		else {
			if (vexRT[Btn5UXmtr2]) basicIntake(127);
			else if (vexRT[Btn5DXmtr2]) basicIntake(-127); 
			else basicIntake(0);
		}
	}
}
