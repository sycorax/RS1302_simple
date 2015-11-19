 The DS1302 uses a 3-wire interface: 
    - bidirectional data.
    - clock
    - chip select
 It is not I2C, not OneWire, and not SPI.
 So the standard libraries can not be used.
 Even the shiftOut() function is not used, since it
 could be too fast (it might be slow enough, 
 but that's not certain).

 I wrote my own interface code according to the datasheet.
 Any three pins of the Arduino can be used.
   See the first defines below this comment, 
   to set your own pins.

 The "Chip Enable" pin was called "/Reset" before.

 The chip has internal pull-down registers.
 This keeps the chip disabled, even if the pins of 
 the Arduino are floating.


 Burst mode
 ----------
 In burst mode, all the clock data is read at once.
 This is to prevent a rollover of a digit during reading.
 The read data is from an internal buffer.

 The burst registers are commands, rather than addresses.
 Clock Data Read in Burst Mode
    Start by writing 0xBF (as the address), 
    after that: read clock data
 Clock Data Write in Burst Mode
    Start by writing 0xBE (as the address), 
    after that: write clock data
 Ram Data Read in Burst Mode
    Start by writing 0xFF (as the address), 
    after that: read ram data
 Ram Data Write in Burst Mode
    Start by writing 0xFE (as the address), 
    after that: write ram data
