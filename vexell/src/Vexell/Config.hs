module Vexell.Config () where

data SensorType = DigitalNone | DigitalInput | DigitalOutput | QuadEncoder
                | SonarCm | SonarInch | IME | Potentiometer | Interrupt
                deriving (Enum)

data ConfigType = ConfInput | ConfOutput | ConfQuadEnc1 | ConfQuadEnc2
                | ConfSonarOut | ConfSonarIn | ConfInterrupt
                deriving (Enum)

sensorTypeToIndex :: SensorType -> Int
sensorTypeToIndex = undefined