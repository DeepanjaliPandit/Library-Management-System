# Library-Management-System
The project “library management system” is a console application using c programming language.<br>
This project is compiled using the GCC compiler.<br>
In this application we can do basic tasks like: <br>
1. Add books<br>                
2. Issue books<br>	            
3. Calculate fine<br>    	      
4. View book<br>
5. Calculate due date<br>
6. Modify the book
7. Return book
8. View borrowed book<br>              
This application Is based on structures in c. <br>
Includes attributes like “SRN”, “semester” specific to school/college students.<br>
<h3>In this program I have incorporated :</h3>

Main structure: library,<br>
Each book has a unique book id, book name, author, and the semester the book belongs to.<br>

Date structure: Date,<br>
holds the date in the format “dd,mm,yy”<br>

Issue structure: issue,<br>
The details of the book, along with srn of the borrower and the date of issue is entered.<br>

Return structure : return,<br>
This structure holds the details of the returned book, as well as the date, the book is to be returned.<br>

<h3>ADD BOOK FUNCTION</h3>
This function is used to add ‘n’ number of books into the library.<br>
The user has to enter the author, name, semester.<br>
The for loop runs n number of times depending on the input of the user.<br>
Count_library counts the number of available books in the library.<br>

<h3>VIEW BOOK FUNCTION</h3>
This function is used to view details and information about the book being borrowed<br>
The book details like “author name, book name, and semester the book belongs to” is displayed for the user upon entering the unique book id<br>
This function is also used to check if the unique id exists in the library structure or not<br>
If not, an error message is displayed.<br>

<h3>MODIFY FUNCTION</h3>
Enables the librarian to enter the id of the book to be modified<br>
If the book id exists in the library, the user is asked to enter the new “book name, author name and the semester”<br>
Upon modification the function displays the updated book details to the user and discards the previous details<br>
If the id entered by the user does not exist in the library, an error message is displayed saying “the book is not found” <br>

<h3>ISSUE BOOK FUNCTION</h3>
This function removes the book details from the library structure and adds it to the issue structure
User is allowed to enter the unique id, if the id exists in the library, user has to enter the srn
The book is removed from the main library. The book details are deleted from the main library
The book of choice is added to the issue library
The date of issue is also stored in the issue structure, to extract the due date
If the unique id entered by the user does not exist in the main library, an error message is displayed.

<h3>DUE DATE FUNCTION</h3>
The due date function has multiple conditions as follows:
If the date of issue belongs to the months having 31 days
If the date of issue is within the 18th day of the month, only the day increments, month remains unchanged. 
If the date of issue exceeds or equals to the 18th day of the month, the month increments, and date changes accordingly.
If the date of issue belongs to the months having 30 days
If the date of issue is within the 17th day of the month, only the day increments, month remains unchanged.
If the date of issue exceeds or equals to the 17th day of the month, the month increments, and date changes accordingly.
When the month is December
If the issued day exceeds or is equal to the 18th day of month, then the year increments by 1, the month is assigned to the value 1. the date changes accordingly.
When it is a leap year
If the issued month is February, and the issued day is within the 16th day of the month. The day increments accordingly
If the issued day exceeds or is equal to the 16th day of the month, then the month increments, the day changes accordingly thus xtracting the required due date.


<h3>FINE FUNCTION</h3>
Fine function has a number of conditions as follows
If the number days, after the due date is zero. The fine is zero
If a student has not returned the book , 30 days after the due date, the student is blacklisted.
Amongst the 30 days
Fine for the first five days is 5 rupees
Fine for the next ten days is 10 rupees per day
Fine for the next 15 days is 15 rupees per day
This function calculates the fine according to the due date and charges the student.





