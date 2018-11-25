# Que1

Design a class Book with the data members to hold title, number of authors, ISBN number, price and number of copies. The title and ISBN number are pointer to characters </br>
Define parameterized and default constructors(number of authors and number of copies equal to 1). </br>
Write getters and setters for each of the member functions. Write the copy constructor. </br>
Write a member function to check the validity of the ISBN number; it is a unique number assigned to a book which can be a 10 digit or 13 digit number.</br>
For 10 digit ISBN number, the sum of all the 10 digits, multiplied by its integer weight, descending from 10 to 1, or ascending from 1 to 10, is a multiple of 11. </br>
10x1 + 9x2 + 8x3 + 7x4 + 6x5 + 5x6 + 4x7 + 3x8 + 2x9 + 1x10 ≡  0 mod 11 </br>
For 13 digit ISBN number, the last digit is a check digit which must range from 0 to 9 and sum of all the thirteen digits multiplied by weights alternating between 1 and 3 is a multiple of 10 </br>
x1 + 3x2 + x3 + 3x4 + x5 + 3x6 + x7 + 3x8 + x9 + 3x10 + x11 + 3x12 + x13 ≡  0 mod 10 </br>
Call the function in the constructor before initializing the ISBN number. </br>
