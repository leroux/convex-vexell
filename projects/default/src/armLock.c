// armLock.c

#include "pidbot.h"

void armLockSystemSet(tVexDigitalState s) {
  vexDigitalPinSet(armLock, s);
}

void armLockInit(void) {
  armLockSystemSet(kVexDigitalLow);
}

void armLockSystemUpdate(void) {
  if (vexControllerGet(Btn7U) || vexControllerGet(Btn7UXmtr2)) { // lock
    armLockSystemSet(kVexDigitalHigh);
    vexMotorSet(rightIntake, 127); // rm this
  } else if (vexControllerGet(Btn7D) || vexControllerGet(Btn7DXmtr2)) { // unlock
    armLockSystemSet(kVexDigitalLow);
  }
}

task armLockTask(void *arg) {
  (void)arg;
  vexTaskRegister("arm lock");

  while (!chThdShouldTerminate()) {
    armLockSystemUpdate();
    vexSleep(25);
  }

  return (task)0;
}