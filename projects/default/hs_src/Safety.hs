module Safety (safetyTask) where

foreign import capi "c_extern.h safetyTask" c_safetyTask :: IO ()
safetyTask :: IO ()
safetyTask = c_safetyTask
