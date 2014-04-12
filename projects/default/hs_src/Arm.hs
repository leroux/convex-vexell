module Arm (armTask) where

foreign import capi "c_extern.h armTask" c_armTask :: IO ()
armTask :: IO ()
armTask = c_armTask
