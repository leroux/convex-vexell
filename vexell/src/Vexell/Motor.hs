module Vexell.Motor (motorPort, motorGet, motorSet) where

import Foreign.C.Types
import Jhc.Type.C

type PinNumber = CInt
newtype MotorPort = MotorPort PinNumber

data MotorType = MotorUndefined | Motor269 | Motor393T | Motor393S deriving (Enum)

data Polarity = Normal | Reversed

data MotorConfig =
  MotorConfig {
    mPort :: MotorPort,
    mType :: MotorType,
    mPolarity :: Polarity
  }

motorPort :: PinNumber -> Maybe MotorPort
motorPort n
  | n < 1 || n > 10 = Nothing
  | otherwise = Just $ MotorPort $ n - 1

foreign import capi "c_extern.h vexMotorSet"
  c_vexMotorSet :: CInt -> CInt -> IO ()
motorSet :: Maybe MotorPort -> CInt -> IO ()
motorSet Nothing _ = return ()
motorSet (Just (MotorPort p)) v = c_vexMotorSet p v

foreign import capi "c_extern.h vexMotorGet"
  c_vexMotorGet :: CInt -> IO CInt
motorGet :: Maybe MotorPort -> IO CInt
motorGet Nothing = return 0
motorGet (Just (MotorPort p)) = c_vexMotorGet p
