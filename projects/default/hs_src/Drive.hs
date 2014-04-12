module Drive (driveTask) where

foreign import capi "c_extern.h driveTask" c_driveTask :: IO ()
driveTask :: IO ()
driveTask = c_driveTask
