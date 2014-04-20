module HangerLock (hangerLockInit, hangerLock, threadHangerLock) where

import Foreign.C.Types
import Control.Monad

import ChibiOS.Threads

foreign import capi "c_extern.h hangerLockInit"
  c_hangerLockInit :: IO ()
hangerLockInit = c_hangerLockInit

foreign import capi "c_extern.h hangerLockSystemUpdate"
  c_hangerLockSystemUpdate :: IO ()
hangerLock :: IO ()
hangerLock = c_hangerLockSystemUpdate

threadHangerLock :: IO ()
threadHangerLock = hangerLockInit >> (forever $ hangerLock >> sleep 20)
