module Pneumatics (pneumaticsTask) where

foreign import capi "c_extern.h pneumaticsTask" c_pneumaticsTask :: IO ()
pneumaticsTask :: IO ()
pneumaticsTask = c_pneumaticsTask
