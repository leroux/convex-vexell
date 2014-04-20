module Drive (drive, threadDrive) where

import Foreign.C.Types
import Control.Monad

import ChibiOS.Threads

foreign import capi "c_extern.h driveTask"
  c_driveTask :: IO ()
driveTask = c_driveTask

foreign import capi "c_extern.h driveSystemArcadeDrive"
  c_driveSystemArcadeDrive :: IO ()
drive :: IO ()
drive = c_driveSystemArcadeDrive

threadDrive :: IO ()
threadDrive = forever $ drive >> sleep 20
