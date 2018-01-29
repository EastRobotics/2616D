#include "main.h"

Gyro gyro;

Gyro getGyro() { return gyro; }

Encoder encExample;

Encoder getEncoderExample() { return encExample; }

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
void initialize() {
  print("[Init] Initializing the robot\n");

  // Set up the LCD and start it
  print("[Init] Setting up the LCD\n");
  lcdInitMenu(1, 4, 1); // Min 1, max 4, home 1
  lcdSetUpdater(implUpdateLCD);
  lcdSetMenuBack(implMenuBack);
  lcdSetMenuNext(implMenuNext);
  lcdSetCycles(true); // When you hit next on the last page, go back to first

  // Set up our drive
  print("[Init] Setting up drive motors\n");
  lcdSetText(uart2, 1, "Init drive...");
  // Front left, back left, front right, back right
  // (Front/back only really matters for holonomic)
  driveInit(MOTOR_UNASSIGNED_1, MOTOR_UNASSIGNED_2, MOTOR_UNASSIGNED_3,
    MOTOR_UNASSIGNED_4);
  // Front left, back left, front right, back right
  // With this set up, you should plug all the wires in the same way
  driveSetReverse(MOTOR_DRIVE_L_REV, MOTOR_DRIVE_L_REV, MOTOR_DRIVE_R_REV,
    MOTOR_DRIVE_R_REV);
  // enableSlew(15); // Set slew rate to 15 (delta motor/call)

  // Set up our autonomous to these modes
  print("[Init] Setting up autonomous modes\n");
  lcdSetText(uart2, 1, "Init auton...");
  autonInit(3); // 3 auton modes
  // setAutonMode(2); Use this to programatically set mode if you must

  // Set up our gyroscope
  print("[Init] Setting gyroscope\n");
  lcdSetText(uart2, 1, "Init gyro...");
  // To use a gyro, uncomment:
  // gyro = gyroInit(ANALOG_GYRO, 0);
  // If you wish to tune, however....
  // gyro = gyroInit(ANALOG_GYRO, 190); // default is 196, this is after tune
  // To tune: 196*((360*rotations)/gyroValue)

  // Set up our encoders
  print("[Init] Setting up encoders\n");
  lcdSetText(uart2, 1, "Init Encs...");
  // To use an encoder, uncomment:
  // encExample = encoderInit(DIGITAL_ENC_TOP, DIGITAL_ENC_BOT, false);
  // 1st port for encoder, 2nd port for encoder, reverse direction
  // Reverse direction will make - into + and + into -. Can also be done
  // by swapping the ports either in code or physically

  // Done init
  print("[Init] Finished, starting LCD menu\n");
  lcdSetText(uart2, 1, "Init menu...");
  lcdStartMenu();
}
