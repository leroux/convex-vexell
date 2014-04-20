module ChibiOS.Threads (sleep) where

import Foreign.C.Types

foreign import capi "c_extern.h chThdSleepMilliseconds"
  c_chThdSleepMilliseconds :: CInt -> IO ()
sleep = c_chThdSleepMilliseconds
