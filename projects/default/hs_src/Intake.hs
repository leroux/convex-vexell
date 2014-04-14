module Intake (threadIntake) where

import ChibiOS.Threads

import Foreign.C.Types
import Control.Monad

foreign import capi "c_extern.h intakeSystemIntakeSet"
  c_intakeSystemIntakeSet :: CShort -> IO ()
intakeSystemIntakeSet = c_intakeSystemIntakeSet

foreign import capi "c_extern.h intakeSystemIntake"
  c_intakeSystemIntake :: IO ()
intakeSystemIntake = c_intakeSystemIntake

intake :: IO ()
intake = intakeSystemIntake >> sleep 25

threadIntake :: IO ()
threadIntake = forever intake