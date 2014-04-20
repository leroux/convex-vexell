module Vexell.Digital (
  -- Functions
  vexDigitalModeSet,
  vexDigitalModeGet,
  vexDigitalPinSet,
  vexDigitalPinGet,
  vexDigitalIntrSet,
  vexDigitalIntrRun,
  vexDigitalIntrCountGet,
  vexExtIrqInit,
  -- Datar
  PinNumber,
  DigitalPin,
  DigitalMode,
  DigitalState
) where

import Foreign
import Foreign.C.Types
import Jhc.Type.C
import Data.Int
import Data.Maybe

type PinNumber = Int
data DigitalPin = DigitalPin PinNumber
data DigitalMode = DigitalInput | DigitalOutput deriving (Enum)
data DigitalState = Low | High deriving (Enum)

digitalPin :: PinNumber -> Maybe DigitalPin
digitalPin n
  | n < 0 || n > 12 = Nothing -- pins bound check
  | otherwise       = Just $ DigitalPin n

foreign import capi "c_extern.h vexDigitalModeSet"
  c_vexDigitalModeSet :: CShort -> CShort -> IO ()
vexDigitalModeSet = c_vexDigitalModeSet

foreign import capi "c_extern.h vexDigitalModeGet"
  c_vexDigitalModeGet :: CShort -> IO CShort
vexDigitalModeGet = c_vexDigitalModeGet

foreign import capi "c_extern.h vexDigitalPinSet"
  c_vexDigitalPinSet :: CShort -> CShort -> IO ()
vexDigitalPinSet = c_vexDigitalPinSet

foreign import capi "c_extern.h vexDigitalPinGet"
  c_vexDigitalPinGet :: CShort -> IO CShort
vexDigitalPinGet = c_vexDigitalPinGet

foreign import capi "c_extern.h vexDigitalIntrSet"
  c_vexDigitalIntrSet :: CShort -> IO ()
vexDigitalIntrSet = c_vexDigitalIntrSet

foreign import capi "c_extern.h vexDigitalIntrRun"
  c_vexDigitalIntrRun :: IO ()
vexDigitalIntrRun = c_vexDigitalIntrRun

foreign import capi "c_extern.h vexDigitalIntrCountGet"
  c_vexDigitalIntrCountGet :: CShort -> IO CWint
vexDigitalIntrCountGet = c_vexDigitalIntrCountGet

foreign import capi "c_extern.h vexExtIrqInit"
  c_vexExtIrqInit :: IO ()
vexExtIrqInit = c_vexExtIrqInit
