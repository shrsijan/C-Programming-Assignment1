1. Write a program that converts from 24-hour notation to 12-hour notation. For example, it
should convert 14:25 to 2:25 PM. The input is given as two integers. There should be at
least three functions, one for input, one to do the conversion, and one for output. Record
the AM/PM information as a value of type char, ‘A’ for AM and ‘P’ for PM. Thus, the
function for doing the conversions will have a call-by-reference formal parameter of type
char to record whether it is AM or PM. (The function will have other parameters as
well.) Include a loop that lets the user repeat this computation for new input values again
and again until the user says he or she wants to end the program.



https://github.com/user-attachments/assets/872c4344-9d87-461a-aea6-61794640f7bf


2. Write a program that requests the current time and a waiting time as two integers for the
number of hours and the number of minutes to wait. The program then outputs what the
time will be after the waiting period. Use 24-hour notation for the times. Include a loop
that lets the user repeat this calculation for additional input values until the user says she
or he wants to end the program.
Modify your program so that it uses 12-hour notation, such as 3:45 PM.

https://github.com/user-attachments/assets/13e0cb16-f2e7-4505-ae80-27b2bc2ef179

Modified Version:

https://github.com/user-attachments/assets/f51d831d-0f28-41c6-bae4-f28d88ab54a6

3. In cold weather, meteorologists report an index called the windchill factor, that takes into
account the wind speed and the temperature. The index provides a measure of the chilling
effect of wind at a given air temperature. Windchill may be approximated by the formula:
W=13.12+0.6215*t-11.37 * v0.16+0.3965*t*v0.016
where
o v= wind speed in m/sect= temperature in degrees Celsius: t <= 10W= windchill index (in
degrees Celsius)
Write a function that returns the windchill index. Your code should ensure that the
restriction on the temperature is not violated.


https://github.com/user-attachments/assets/f2d6a6e2-3ddf-46df-ba1d-0164a676a0bf



