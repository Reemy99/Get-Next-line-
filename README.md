# Get-Next-line-
This project is about programming a function that allows you to read content line by line. This is done by returning a line read from a file descriptor.

__________________________________________

# Get_Next_Line Submission
When submitting the project, you only require the following 3 files if your not doing the bonus:

get_next_line.c
get_next_line_utils.c
get_next_line.h

__________________________________________

# How to start
You need to read one character at a time, until you've read the entire line, and detect a '/n'.

1) You should declare some buffer which you read a character, then copy it into the buffer.
2) You need to make sure you don't overfill your buffer in the even that you do run over it's length.
3) Keep reading until you find a '/n' character. Then process the line that you have created, and start the next one.

__________________________________________

# You need to know what static variable is
program, whereas a normal variable is destroyed when a function is over .
The static variable inside the function holds the value not only till the end of the function block but till the end of the entire program

__________________________________________
