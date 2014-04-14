{-# LANGUAGE ForeignFunctionInterface #-}

module Vexell.Vex.Motor (vexMotorGet, vexMotorSet) where

import Foreign.C.Types

foreign import capi "c_extern.h vexMotorGet"
  c_vexMotorGet :: CInt -> IO Int
vexMotorGet = c_vexMotorGet

foreign import capi "c_extern.h vexMotorSet"
  c_vexMotorSet :: CInt -> CInt -> IO ()
vexMotorSet = c_vexMotorSet
