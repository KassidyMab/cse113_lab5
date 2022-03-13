Author: Kassidy Maberry
Assignment: lab5
Date: 2022/02/13
-----
Purpose
-----
- array_struct.c is a program that contains various operations for working with
a struct that is in array format. The example used is student information and
organizing said information.

- array.c  contains most satistical functions for lab5.c. The program can find
various things like the average, mean, or amount of even elements in a list.

- lab5.c displays the information array.c figures out and provides it with
information. This will write out all of those in a struct.

- lab5_q2.c is a program that shows how enumeration works. By printing out the
values name and then what the value is equal to.

- lab5_q3.c is a program that can find the distance between two user given
inputs.

- lab5_q4.c is a program that figures out the sign of someone on any given
date.
-----
Conclusion
-----
- I learned about goto statements, how to use structs, and enumeration.

- Pair programming did not help.

- I worked alone for the most part however there was one part where me and my
roommate were discussing various ways you could implement the input for a menu
system.

- I ran into two problems one of which was because I declared a struct after my
function declarations causing problems. To fix this I started declaring structs
before my prototyping. The other one was with a menu system. I had two 
different implementations that worked however I didn't want to use scanf and
fgets created a problem with its newline character. To fix this I had it detect
when a newline character was found and then use a goto statement to the input 
statement. Preventing the program from restarting because of an input the user
never gave.

- The menu system could probably have a more elegant solution instead of using
a goto statement to fix the issue.
-----

