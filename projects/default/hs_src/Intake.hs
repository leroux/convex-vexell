module Intake (intake, threadIntake) where

import Foreign.C.Types
import Control.Monad

import ChibiOS.Threads

foreign import capi "c_extern.h intakeSystemIntakeSet"
  c_intakeSystemIntakeSet :: CShort -> IO ()
intakeSystemIntakeSet = c_intakeSystemIntakeSet

foreign import capi "c_extern.h intakeSystemIntake"
  c_intakeSystemIntake :: IO ()
intake :: IO ()
intake = c_intakeSystemIntake

threadIntake :: IO ()
threadIntake = forever $ intake >> sleep 20
