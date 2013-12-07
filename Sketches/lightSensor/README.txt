This sketch uses the adafruit GA1A1S202 light sensor. 

The program will first try and establish ambient light in luxes. It will run for 500 samples with a 50ms delay between sample. This will establish a floor/ceiling. 

Once this ambient window is established, the loop will run forever and break when a reading falls outside the bounds of the high and low and display the luxes. 

This is the beginning basis to determine if a light sensor can be used to read morse code from an LED. 

NOTE: if the room's ambient light fluctuates greatly, the range for the ambient floor/ceiling might be too high/low to register and changes. 
