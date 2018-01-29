#include "main.h"
int examplePage = 0;

void implUpdateLCD(bool userCaused, int page) {
  lcdClear(uart2);
  switch (page) {
  // [Page 1] Home Screen ------------------------------------------------------
  case 1: {
    lcdPrintCentered("-={ 2616 }=-", 0);
    lcdPrintCentered("Idk, some text", 1);
  } break; // ------------------------------------------------------------------

  // [Page 2] Auton mode selector ----------------------------------------------
  case 2: {
    lcdPrintTitle("AutonMode");
    const char *autonName;
    switch (getAutonMode()) { // Set name based on auton mode
    case 1: // Mode 1 selected
      autonName = "Do Nothing";
      break;
    case 2: // Mode 2 selected
      autonName = "Test mode 1";
      break;
    case 3: // Mode 3 selected
      autonName = "Test mode 2";
      break;
    default: { // Unknown mode
      char temp[17];
      snprintf(temp, 17, "Unknown %d", page);
      autonName = temp;
    }
    }
    static char temp[16]; // Create buffer for following line
    sprintf(temp, "%c %s %c", 0xBC, autonName, 0xBB); // Set up auton name
    lcdPrintCentered(temp, 2);                        // Print auton name
  } break; // ------------------------------------------------------------------

  // [Page 3] Sensor example ---------------------------------------------------
  case 3: {
    lcdPrintTitle("SensorExmpl");
    lcdPrint(uart2, 1, "Val: %d", analogRead(1));
  } break; // ------------------------------------------------------------------

  // [Page 4] Example menu -----------------------------------------------------
  case 4: {
    lcdPrintTitle("SensorExmpl");
    const char* pageName = "What";
    // Sometimes cleaner with a swtich....
    if (examplePage == 0) {
      pageName = "Page 1";
    } else if (examplePage == 1) {
      pageName = "Page 2";
    } else if (examplePage == 2) {
      pageName = "Page 3";
    }
    // Print out that name centered
    static char temp[16]; // Create buffer for following line
    sprintf(temp, "%c %s %c", 0xBC, pageName, 0xBB); // Set up auton name
    lcdPrintCentered(temp, 2);
  } break; // ------------------------------------------------------------------

  // [Page ?] Unknown page -----------------------------------------------------
  // Handles pages that for whatever reason don't draw anything
  // Highly suggested to keep this here
  default:
    lcdPrint(uart2, 1, "Page? %d", page);
    break; // ------------------------------------------------------------------
  }
}

// Note, only pages that need in-menu actions should use this
void implMenuNext(int page) {
  switch (page) {
  // [Page 2] Auton mode selector ----------------------------------------------
  case 2: {
    int nextMode = getAutonMode() + 1;
    if (nextMode > getAutonModeMax())
      setAutonMode(getAutonModeMin());
    else
      setAutonMode(nextMode);
  } break; // ------------------------------------------------------------------
  // [Page 4] Example menu -----------------------------------------------------
  case 4: {
    // Increment the page one, and if this is more than the highest page, go
    // back to the first page
    if (++examplePage > 2)
      examplePage = 0;
  } break; // ------------------------------------------------------------------
  }
  implUpdateLCD(true, page);
  lcdResetAutoRefresh();
}

// Note, only pages that need in-menu actions should use this
void implMenuBack(int page) {
  switch (page) {
  // [Page 2] Auton mode selector ----------------------------------------------
  case 2: {
    int nextMode = getAutonMode() - 1;
    if (nextMode < getAutonModeMin())
      setAutonMode(getAutonModeMax());
    else
      setAutonMode(nextMode);
  } break; // ------------------------------------------------------------------
  // [Page 4] Example menu -----------------------------------------------------
  case 4: {
    // Decrement the page one, and if this is less than the lowest page, go
    // back to the last page
    if (--examplePage < 0)
      examplePage = 2;
  } break; // ------------------------------------------------------------------
  }
  implUpdateLCD(true, page);
  lcdResetAutoRefresh();
}
