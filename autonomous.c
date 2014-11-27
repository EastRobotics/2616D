#include "functions.c"

void ourAutonomous() {
	basicDrive(100, 100);
	wait1Msec(500);
	basicDrive(0, 0);
}