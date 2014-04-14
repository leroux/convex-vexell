// pneumatics.c

#include "pidbot.h"

void pneumaticsSystemSet(tVexDigitalState s) {
  vexDigitalPinSet(solenoid_1, s);
  vexDigitalPinSet(solenoid_2, s);
}

void pneumaticsInit(void) {
  pneumaticsSystemSet(kVexDigitalLow);
}

void pneumaticsSystemUpdate(void) {
  if (vexControllerGet(Btn7U) || vexControllerGet(Btn7UXmtr2)) { // lock
    pneumaticsSystemSet(kVexDigitalHigh);
    vexMotorSet(rightIntake, 127); // rm this
  } else if (vexControllerGet(Btn7D) || vexControllerGet(Btn7DXmtr2)) { // unlock
    pneumaticsSystemSet(kVexDigitalLow);
  }
}

task pneumaticsTask(void *arg) {
  (void)arg;
  vexTaskRegister("pneumatics");

  while (!chThdShouldTerminate()) {
    pneumaticsSystemDo();
    vexSleep(25);
  }

  return (task)0;
}