# MyProject001
1.	In the assignment we are supposed to create a single-instance module to debounce push buttons to the requirements below:
i.	The module shall be testable on PC and Teensy b. The module shall be fully tested, and the code coverage shall be 100%. 
ii.	The module shall be able to debounce multiple buttons (max. 8 buttons) 
iii.	The pull-up resistors of the pins connected to the buttons shall be activated 
iv.	To take samples(read) from the pins and update the debounced state of the buttons there shall be an update function in the interface of the module. The client of your module calls this function internally.
a.	If there are 5 consecutive states of the same value, it means that the state of the button is stable and reliable. 
v.	The module shall detect rising and falling edges in the debounced state of buttons.
Tools used are:1) Hardware- Teensy 3.5,push buttons
2)Software- Visual Studio code (IDE), Platform IO(cross platform development environment).
3)Programming Language-Embedded C
4)Testing Methodology-TDD (test driven development)
