module Arm (armInit, arm, threadArm) where

import Foreign.C.Types
import Control.Monad

import ChibiOS.Threads

foreign import capi "c_extern.h armInit"
  c_armInit :: IO ()
armInit = c_armInit

foreign import capi "c_extern.h armSystemLift"
  c_armSystemLift :: IO ()
arm :: IO ()
arm = c_armSystemLift

threadArm :: IO ()
threadArm = armInit >> (forever $ arm >> sleep 20)
