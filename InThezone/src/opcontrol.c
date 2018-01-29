
#include "main.h"

void operatorControl() {
	while (true) { // True is cooler than 1
		// Drive arcade, using the joystick channels 3 (Forward), 1 (Turn),
    // and 0 for strafe since not holonomic
    driveWithLogic(joystickGetAnalog(1, 3), joystickGetAnalog(1, 1), 0);
		// but since you guys are nerds, if you want tank, use this instead:
		// driveTank(joystickGetAnalog(1, 3), joystickGetAnalog(1, 1));
		// This will only use slew, no linearize or thresholds, feel free to change
		// that if you wishs

		delay(20); // Give other things time to run, recommended to keep this
	}
}
