module Vexell.Controller where

import Foreign
import Foreign.C.Types
import Jhc.Type.C
import Data.Maybe

data JoyButton = Btn8D | Btn8L | Btn8U | Btn8R | Btn7D -- main
               | Btn7L | Btn7U | Btn7R | Btn5D | Btn5U | Btn6D
               | Btn6U | Btn5  | Btn6  | Btn7  | Btn8  | BtnAny
               | Btn8DXmtr2  -- partner joy
               | Btn8LXmtr2 | Btn8UXmtr2 | Btn8RXmtr2 | Btn7DXmtr2
               | Btn7LXmtr2 | Btn7UXmtr2 | Btn7RXmtr2 | Btn5DXmtr2
               | Btn5UXmtr2 | Btn6DXmtr2 | Btn6UXmtr2 | Btn5Xmtr2
               | Btn6Xmtr2  | Btn7Xmtr2  | Btn8Xmtr2  | BtnAnyXmtr2
               deriving (Eq)

data JoyAxis = Ch1 | Ch2 | Ch3 | Ch4 | AcclX | AcclY | AcclZ
             | Ch1Xmtr2 | Ch2Xmtr2 | Ch3Xmtr2| Ch4Xmtr2
             | AcclXXmtr2 | AcclYXmtr2 | AcclZXmtr2
             deriving (Eq)

foreign import capi "c_extern.h vexControllerGet"
  c_vexControllerGet :: CInt -> IO CInt
vexControllerGet = c_vexControllerGet

buttonToIndex :: JoyButton -> Maybe CInt
buttonToIndex b = lookup b buttonMap
  where buttonMap = [(Btn8D, 4), (Btn8L, 5), (Btn8U, 6), (Btn8R, 7), (Btn7D, 8),
                     (Btn7L, 9), (Btn7U, 10), (Btn7R, 11), (Btn5D, 12), (Btn5U, 13),
                     (Btn6D, 14), (Btn6U, 15), (Btn5, 19), (Btn6, 20), (Btn7, 21),
                     (Btn8, 22), (BtnAny, 23), (Btn8DXmtr2, 132), (Btn8LXmtr2, 133),
                     (Btn8UXmtr2, 134), (Btn8RXmtr2, 135), (Btn7DXmtr2, 136),
                     (Btn7LXmtr2, 137), (Btn7UXmtr2, 138), (Btn7RXmtr2, 139),
                     (Btn5DXmtr2, 140), (Btn5UXmtr2, 141), (Btn6DXmtr2, 142),
                     (Btn6UXmtr2, 143), (Btn5Xmtr2, 147), (Btn6Xmtr2, 148),
                     (Btn7Xmtr2, 149), (Btn8Xmtr2, 150), (BtnAnyXmtr2, 151)]

axisToIndex :: JoyAxis -> Maybe CInt
axisToIndex a = lookup a axisMap
  where axisMap = [(Ch1, 0), (Ch2, 1), (Ch3, 2), (Ch4, 3), (AcclX, 16), (AcclY, 17),
                   (AcclZ, 18), (Ch1Xmtr2, 128), (Ch2Xmtr2, 129), (Ch3Xmtr2, 130),
                   (Ch4Xmtr2, 131), (AcclXXmtr2, 144), (AcclYXmtr2, 145), (AcclZXmtr2, 145)]

buttonGet :: JoyButton -> IO Bool
buttonGet b = do
  let i = buttonToIndex b
  case i of
    Nothing -> return False
    Just x  -> do
      v <- vexControllerGet x
      return $ v == 1

axisGet :: JoyAxis -> IO CInt
axisGet a = do
  let i = axisToIndex a
  case i of
    Nothing -> return 0
    Just x -> vexControllerGet x