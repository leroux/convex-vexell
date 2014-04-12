{-# LANGUAGE ForeignFunctionInterface #-}
module Main where

import Arm
import Drive
import Intake
import Pneumatics
import Safety

import Control.Concurrent
import Control.Monad

foreign export ccall "hs_vexUserSetup" vexUserSetup :: IO ()
foreign export ccall "hs_vexUserInit" vexUserInit :: IO ()
foreign export ccall "hs_vexOperator" vexOperator :: IO ()

foreign import capi "c_extern.h vexUserSetup" c_vexUserSetup :: IO ()
foreign import capi "c_extern.h vexUserInit" c_vexUserInit :: IO ()
foreign import capi "c_extern.h vexOperator" c_vexOperator :: IO ()

vexUserSetup :: IO ()
vexUserSetup = c_vexUserSetup

vexUserInit :: IO ()
vexUserInit = return ()

vexOperator :: IO ()
vexOperator = mapM_ forkOS [driveTask, armTask, intakeTask, pneumaticsTask]

main :: IO ()
main = return ()
