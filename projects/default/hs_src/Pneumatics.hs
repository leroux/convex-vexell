module Pneumatics (threadPneumatics) where

import ChibiOS.Threads

import Foreign.C.Types
import Control.Monad

foreign import capi "c_extern.h pneumaticsInit"
  c_pneumaticsInit :: IO ()
pneumaticsInit = c_pneumaticsInit

foreign import capi "c_extern.h pneumaticsSystemUpdate"
  c_pneumaticsSystemUpdate :: IO ()
pneumaticsSystemUpdate = c_pneumaticsSystemUpdate

pneumatics :: IO ()
pneumatics = pneumaticsSystemUpdate >> sleep 25

threadPneumatics :: IO ()
threadPneumatics = pneumaticsInit >> forever pneumatics