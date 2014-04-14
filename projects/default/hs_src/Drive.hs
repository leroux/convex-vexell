module Drive (threadDrive) where

import ChibiOS.Threads

import Foreign.C.Types
import Control.Monad

foreign import capi "c_extern.h driveTask"
  c_driveTask :: IO ()
driveTask = c_driveTask

foreign import capi "c_extern.h driveSystemArcadeDrive"
  c_driveSystemArcadeDrive :: IO ()
driveSystemArcadeDrive = c_driveSystemArcadeDrive

drive :: IO ()
drive = driveSystemArcadeDrive >> sleep 25

threadDrive :: IO ()
threadDrive = forever drive
