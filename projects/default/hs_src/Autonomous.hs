module Autonomous (autonomousTask, autonomous) where

foreign export ccall "hs_vexAutonomous" vexAutonomous :: IO ()

foreign import capi "c_extern.h vexAutonomous" c_vexAutonomous :: IO ()
vexAutonomous :: IO ()
vexAutonomous = do
  mapM_ forkOS [armTask]
  void autonomous

foreign import capi "c_extern.h autonomous" c_autonomous :: IO ()
autonomous :: IO ()
autonomous = c_autonomous

