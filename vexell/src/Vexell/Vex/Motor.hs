{-# LANGUAGE ForeignFunctionInterface #-}

module Vexell.Vex.Motor where

import Foreign.C.Types

foreign import capi "c_extern.h vexMotorGet" c_vexMotorGet :: CInt -> IO Int
foreign import capi "c_extern.h vexMotorSet" c_vexMotorSet :: CInt -> CInt -> IO ()