#include "functions.c"

void controller() {
	bool slowDrive = false;

	while(true) {

		//Drive
		// if (vexRT[Btn6DXmtr2]) slowDrive = true;
		// else if (vexRT[Btn6UXmtr2]) slowDrive = false;

		driveNoStall(
			slowDrive ? (vexRT[Ch3] / 2.2) : vexRT[Ch3],
			slowDrive ? (vexRT[Ch2] / 2.2) : vexRT[Ch2],
			10);

		//Lift
		if (vexRT[Btn6U]) basicLift(127);
		else if (vexRT[Btn6D]) basicLift(-127);
		else {
			if (abs(vexRT[Ch3Xmtr2]) >= 10) basicLift(vexRT[Ch3Xmtr2]);
			else if (vexRT[Btn7UXmtr2]) basicLift(70);
			else if (vexRT[Btn7DXmtr2]) basicLift(-25);
			else if (vexRT[Btn5UXmtr2]) basicLift(20);
			else basicLift(30);
		}

		//Intake
		if (vexRT[Btn5U]) basicIntake(127);
		else if (vexRT[Btn5D]) basicIntake(-127);
		else {
			if (abs(vexRT[Ch2Xmtr2]) >= 10) basicIntake(-(vexRT[Ch2Xmtr2]));
			else basicIntake(0);
		}

		//Skyrise
		if (vexRT[Btn6UXmtr2]) SensorValue[skyrisePneumatics] = 0;
		else if (vexRT[Btn6DXmtr2]) SensorValue[skyrisePneumatics] = 1;
	}
}
