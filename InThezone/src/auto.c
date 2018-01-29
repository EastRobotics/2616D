#include "main.h"

// To change the name you see for autons, see lcd_impl.c
void autonomous() {
  switch (getAutonMode()) {
  // We normally leave this as "Do nothing"
  // Gives you the option to do nothing if autons conflict, and if you forget
  // to set auton, you at least wont run the wrong one and break the bot
  case 1:
    print("Ran auton one!\n");
    break;

  case 2:
    print("Ran auton one!\n");
    break;

  case 3:
    print("Ran auton one!\n");
    break;

  default:
    print("Ran auton that wasn't given a case!");
  }

  /*
  ** Clean up
  */
  if (isOnline()) { // Will only run if it detects you are plugged into switch
    // Clean up anything you want to get max speeds at comp
    // Tbh even we don't ever use this
  }
}
