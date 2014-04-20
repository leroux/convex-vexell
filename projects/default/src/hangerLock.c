// hangerLock.c

#include "pidbot.h"

void hangerLockSystemSet(tVexDigitalState s) {
  vexDigitalPinSet(hangerLock, s);
}

void hangerLockInit(void) {
  hangerLockSystemSet(kVexDigitalLow);
}

void hangerLockSystemUpdate(void) {
  if (vexControllerGet(Btn7U) || vexControllerGet(Btn7UXmtr2)) { // lock
    hangerLockSystemSet(kVexDigitalHigh);
    vexMotorSet(rightIntake, 127); // rm this
  } else if (vexControllerGet(Btn7D) || vexControllerGet(Btn7DXmtr2)) { // unlock
    hangerLockSystemSet(kVexDigitalLow);
  }
}

task hangerLockTask(void *arg) {
  (void)arg;
  vexTaskRegister("arm lock");

  while (!chThdShouldTerminate()) {
    hangerLockSystemUpdate();
    vexSleep(25);
  }

  return (task)0;
}