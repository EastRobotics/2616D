#include "functions.c"

void controller() {
	bool slowDrive = false;

	while(true) {

		//Drive
		// if (vexRT[Btn6DXmtr2]) slowDrive = true;
		// else if (vexRT[Btn6UXmtr2]) slowDrive = false;


		if (vexRT[Btn8U]) basicDrive(70, 70);
		else if (vexRT[Btn8D]) basicDrive(-70, -70);
		else {
			driveNoStall(
				slowDrive ? (vexRT[Ch3] / 2.2) : vexRT[Ch3],
				slowDrive ? (vexRT[Ch2] / 2.2) : vexRT[Ch2],
				10);
		}

		//Lift
		if (vexRT[Btn6U]) basicLift(127);
		else if (vexRT[Btn6D]) basicLift(-127);
		else {
			if (abs(vexRT[Ch3Xmtr2]) >= 10) basicLift(vexRT[Ch3Xmtr2]);
			else if (vexRT[Btn7UXmtr2]) basicLift(70);
			else if (vexRT[Btn7DXmtr2]) basicLift(-25);
			else if (vexRT[Btn5UXmtr2]) basicLift(20);
			else basicLift(0);
		}

		//Intake
		if (vexRT[Btn5U]) basicIntake(127);
		else if (vexRT[Btn5D]) basicIntake(-127);
		else {
			if (abs(vexRT[Ch2Xmtr2]) >= 10) basicIntake(-(vexRT[Ch2Xmtr2]));
			else basicIntake(0);
		}

		//Skyrise
		//6U + 6D for right pneumatics
		if (vexRT[Btn6UXmtr2]) SensorValue[skyriseRight] = 0;
		else if (vexRT[Btn6DXmtr2]) SensorValue[skyriseRight] = 1;

		//5D for toggle pneumatics
		if(SensorValue(skyriseLeft) == 0) {
			while(vexRT[Btn5DXmtr2]) {
				SensorValue[skyriseLeft] = 1;
			}
		} 
		else {
			while(vexRT[Btn5DXmtr2]) {
				SensorValue[skyriseLeft] = 0;
			}	
		}
	}
}
