module Vexell.Motor (vexMotorGet, vexMotorSet) where

import Foreign.C.Types
import Jhc.Type.C

type PinNumber = CInt
newtype MotorPort = MotorPort PinNumber

motorPort :: PinNumber -> Maybe MotorPort
motorPort n
  | n < 1 || n > 10 = Nothing
  | otherwise = Just $ MotorPort (n - 1)

data MotorType = MotorUndefined | Motor269 | Motor393T | Motor393S deriving (Enum)

data Polarity = Normal | Reversed

data MotorConfig =
  MotorConfig {
    mPort :: MotorPort,
    mType :: MotorType,
    mPolarity :: Polarity
  }

foreign import capi "c_extern.h vexMotorSet"
  c_vexMotorSet :: CInt -> CInt -> IO ()
vexMotorSet :: MotorPort -> CInt -> IO ()
vexMotorSet (MotorPort p) v = c_vexMotorSet p v

foreign import capi "c_extern.h vexMotorGet"
  c_vexMotorGet :: CInt -> IO CInt
vexMotorGet :: MotorPort -> IO CInt
vexMotorGet (MotorPort p) = c_vexMotorGet p
