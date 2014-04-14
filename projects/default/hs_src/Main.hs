{-# LANGUAGE ForeignFunctionInterface #-}
module Main where

import Autonomous
import Arm
import Drive
import Intake
import Pneumatics
import Safety

import Control.Concurrent
import Control.Monad

import Vexell.Vex.Motor

foreign export ccall "hs_vexUserSetup" hs_vexUserSetup :: IO ()
foreign export ccall "hs_vexUserInit" hs_vexUserInit :: IO ()
foreign export ccall "vexOperator" vexOperator :: IO ()
foreign export ccall "vexAutonomous" vexAutonomous :: IO ()

foreign import capi "c_extern.h vexUserSetup" c_vexUserSetup :: IO ()
foreign import capi "c_extern.h vexUserInit" c_vexUserInit :: IO ()
foreign import capi "c_extern.h c_vexOperator" c_vexOperator :: IO ()
foreign import capi "c_extern.h c_vexAutonomous" c_vexAutonomous :: IO ()

hs_vexUserSetup :: IO ()
hs_vexUserSetup = return ()

hs_vexUserInit :: IO ()
hs_vexUserInit = return ()

vexOperator :: IO ()
--vexOperator = void $ forkOS intakeTask
--vexOperator = mapM_ (void . forkOS) [armTask, intakeTask]
vexOperator = mapM_ (void . forkOS) [driveTask, armTask, intakeTask, pneumaticsTask]

vexAutonomous :: IO ()
vexAutonomous = do
  mapM_ forkOS [armTask]
  void autonomous

main :: IO ()
main = return ()
