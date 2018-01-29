 #ifndef PORTS_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define PORTS_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
** Motors
** (1-10)
*/
  #define MOTOR_UNASSIGNED_1 1   // Unnamed motor 1
  #define MOTOR_UNASSIGNED_2 2   // Unnamed motor 2
  #define MOTOR_UNASSIGNED_3 3   // Unnamed motor 3
  #define MOTOR_UNASSIGNED_4 4   // Unnamed motor 4
  #define MOTOR_UNASSIGNED_5 5   // Unnamed motor 5
  #define MOTOR_UNASSIGNED_6 6   // Unnamed motor 6
  #define MOTOR_UNASSIGNED_7 7   // Unnamed motor 7
  #define MOTOR_UNASSIGNED_8 8   // Unnamed motor 8
  #define MOTOR_UNASSIGNED_9 9   // Unnamed motor 9
  #define MOTOR_UNASSIGNED_10 10 // Unnamed motor 10

  // Drive directions
    #define MOTOR_DRIVE_R_REV true  // Whether or not to reverse right drive
    #define MOTOR_DRIVE_L_REV false // Whether or not to reverse left drive

/*
** Analog
** (1-8)
*/
  #define ANALOG_UNASSIGNED_1 1 // Unnamed analog 1
  #define ANALOG_UNASSIGNED_2 2 // Unnamed analog 2
  #define ANALOG_UNASSIGNED_3 3 // Unnamed analog 3
  #define ANALOG_UNASSIGNED_4 4 // Unnamed analog 4
  #define ANALOG_UNASSIGNED_5 5 // Unnamed analog 5
  #define ANALOG_UNASSIGNED_6 6 // Unnamed analog 6
  #define ANALOG_UNASSIGNED_7 7 // Unnamed analog 7
  #define ANALOG_UNASSIGNED_8 8 // Unnamed analog 8

/*
** Digital
** (1-12) - Although not sure with PROS
** Can't use 4 & 10 together because interrupts
*/
  // Auton
  #define DIGITAL_UNASSIGNED_1 1   // Unnamed digital 1
  #define DIGITAL_UNASSIGNED_2 2   // Unnamed digital 2
  #define DIGITAL_UNASSIGNED_3 3   // Unnamed digital 3
  #define DIGITAL_UNASSIGNED_4 4   // Unnamed digital 4
  #define DIGITAL_UNASSIGNED_5 5   // Unnamed digital 5
  #define DIGITAL_UNASSIGNED_6 6   // Unnamed digital 6
  #define DIGITAL_UNASSIGNED_7 7   // Unnamed digital 7
  #define DIGITAL_UNASSIGNED_8 8   // Unnamed digital 8
  #define DIGITAL_UNASSIGNED_9 9   // Unnamed digital 9
  #define DIGITAL_DO_NOT_USE 10    // Seriously, do not use this.
  #define DIGITAL_UNASSIGNED_11 11 // Unnamed digital 11
  #define DIGITAL_UNASSIGNED_12 12 // Unnamed digital 12

/*
** I2C (WARNING: STATIC SHOCK)
** (0-IME_ADDR_MAX, AKA 0x1F)
*/

#ifdef __cplusplus
}
#endif

#endif
