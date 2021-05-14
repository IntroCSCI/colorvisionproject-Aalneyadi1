# Anti-Colorblind

## Developer

Ahmed Mohammed Alneyadi

### v0.2 Updates

This program will currently print a specific color square measure of which number inside the file. I jointly fixed a bug from the previous version of the program, it usually prints the program some values that do not look like color values.

### v1.0 Updates

*Coming soon*

## Description

My program asks for the file name, reads the file, and prints the colour the colour the six characters within the file. Color values ​​are described in hex format. The program then prints out what percentage distinctive colours ar within the file.

## C++ Guide

### Variables and Data Types

I used multiple strings such as (filaName) that store the file name in the user information. And (line) which stores each line with color value makes a difference once in the file. I have used a four variable which is (color value), and this variable stores each hex character. I used the same (interview), and it represents the position of the characters of color values. Finally, I used (reader) from ifstream, which represents the variable that reads the opened files.

### Console Input and Output

I used multiple console outputs. The base file has to be raised by the user for the name of the file that needs to be opened. The second is to create an end between the user's input and the program's output. And those who have to print color values found in the unit area contained within the file. I used a total of 2 console inputs, basic for storing file names. And the second is to store each line inside an open file with a color value.

### Decisions and Iterations

I used 2 choices in my program, and each of them was of the same type (if any). The purpose of the primary (if) call in my program is to see if the file name listed exists and can be opened, and if this is true, if not, the program breaks down. In the second (if at all) call in my program to see whether it has worked hash # sign is present, and if it is true and, if not, it does nothing. I have 2 examples of repetition in my program. The basic one is (while loop), and this loop helps to hide the colored values until the program reached the tip of the opened file, and this is the result of the (in) state that (! قاری. Eof). Another example of repetition in my program is (loop), and it is helpful for me to print this program, which varies the square scale between the hexes.

### File Input and Output and Arrays/Vectors

I used file input to open the file and sketch it completely, when it was not written. File input helped to browse the file and achieve the goal of the US state, which is reading color values from the open file. I used vectors to browse colours from the file. I used the array to list the names of the common colours of the work in CSS and their color values within the hex.

### Functions and Classes

I created a color category to store color data and implemented strategies to try to change the color from string to paint, to check whether the conversion from color to string and the process of equal operator can be checked. 2 color area units is equal. I used an Funtion to find out if there is a color inside the color table and if it is not in the color table, embody that color. It has developed a single Function to handle the entry of the latest colors inside the table. The parameters regarding the object are that the color table has gone through vectors and pointers. With reference, you will edit the object / class from the Function itself. It is also very abundant because the PC does not need to copy the object. This operation shows that the new color is special.
