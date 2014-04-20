module ArmLock (armLockInit, armLock, threadArmLock) where

import Foreign.C.Types
import Control.Monad

import ChibiOS.Threads

foreign import capi "c_extern.h armLockInit"
  c_armLockInit :: IO ()
armLockInit = c_armLockInit

foreign import capi "c_extern.h armLockSystemUpdate"
  c_armLockSystemUpdate :: IO ()
armLock = c_armLockSystemUpdate

threadArmLock :: IO ()
threadArmLock = armLockInit >> (forever $ armLock >> sleep 20)
