# Debouncer Project Details
Assignment – Debouncer
Programming and Development of Embedded Systems
In this assignment, you are supposed to create a single-instance 
module(debouncer)to debounce push buttons according to the 
requirements below.
Requirements
1.Use TDD and follow the dual-targeting strategy to develop and test the 
module.
a. The module shall be testable on PC and Teensy
b. The module shall be fully tested and the code coverage shall be 100%.
2. The module shall be able to debounce multiple buttons (max. 8 buttons)
3. The pull-up resistors of the pins connected to the buttons shall be 
activated
4. To take samples(read) from the pins and update the debounced state of 
the buttons there shall be an update function in the interface of the module. 
The client of your module calls this function intervally.
a.If there are 5 consecutive states of the same value, it means that the 
state of the button is stable and reliable.
5.The module shall detect rising and falling edges in the debounced state 
of button
Tools used are:
1)Software- Visual Studio code (IDE), Platform IO(cross platform development environment).
2)Programming Language-Embedded C

