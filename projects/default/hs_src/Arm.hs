module Arm (threadArm) where

import ChibiOS.Threads

import Foreign.C.Types
import Control.Monad

foreign import capi "c_extern.h armInit"
  c_armInit :: IO ()
armInit = c_armInit

foreign import capi "c_extern.h intakeSystemIntakeSet"
  c_intakeSystemIntakeSet :: CShort -> IO ()
intakeSystemIntakeSet = c_intakeSystemIntakeSet

foreign import capi "c_extern.h armSystemLift"
  c_armSystemLift :: IO ()
armSystemLift = c_armSystemLift

arm :: IO ()
arm = armSystemLift >> sleep 25

threadArm :: IO ()
threadArm = armInit >> forever arm
