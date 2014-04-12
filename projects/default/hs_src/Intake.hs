module Intake (intakeTask) where

foreign import capi "c_extern.h intakeTask" c_intakeTask :: IO ()
intakeTask :: IO ()
intakeTask = c_intakeTask