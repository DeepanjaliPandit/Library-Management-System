# Library-Management-System 📚
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

<h3>ADD BOOK FUNCTION 📖</h3>
This function is used to add ‘n’ number of books into the library.<br>
The user has to enter the author, name, semester.<br>
The for loop runs n number of times depending on the input of the user.<br>
Count_library counts the number of available books in the library.<br>

<h3>VIEW BOOK FUNCTION 📒</h3>
This function is used to view details and information about the book being borrowed<br>
The book details like “author name, book name, and semester the book belongs to” is displayed for the user upon entering the unique book id<br>
This function is also used to check if the unique id exists in the library structure or not<br>
If not, an error message is displayed.<br>

<h3>MODIFY FUNCTION 📓</h3>
Enables the librarian to enter the id of the book to be modified<br>
If the book id exists in the library, the user is asked to enter the new “book name, author name and the semester”<br>
Upon modification the function displays the updated book details to the user and discards the previous details<br>
If the id entered by the user does not exist in the library, an error message is displayed saying “the book is not found” <br>

<h3>ISSUE BOOK FUNCTION 🔖</h3>
This function removes the book details from the library structure and adds it to the issue structure<br>
User is allowed to enter the unique id, if the id exists in the library, user has to enter the srn<br>
The book is removed from the main library. The book details are deleted from the main library<br>
The book of choice is added to the issue library<br>
The date of issue is also stored in the issue structure, to extract the due date<br>
If the unique id entered by the user does not exist in the main library, an error message is displayed.<br>

<h3>DUE DATE FUNCTION 📆</h3>
The due date function has multiple conditions as follows:<br>
If the date of issue belongs to the months having 31 days<br>
If the date of issue is within the 18th day of the month, only the day increments, month remains unchanged.<br>
If the date of issue exceeds or equals to the 18th day of the month, the month increments, and date changes accordingly.<br>
If the date of issue belongs to the months having 30 days<br>
If the date of issue is within the 17th day of the month, only the day increments, month remains unchanged.<br>
If the date of issue exceeds or equals to the 17th day of the month, the month increments, and date changes accordingly.<br>
When the month is December<br>
If the issued day exceeds or is equal to the 18th day of month, then the year increments by 1, the month is assigned to the value 1. the date changes accordingly.<br>
When it is a leap year<br>
If the issued month is February, and the issued day is within the 16th day of the month. The day increments accordingly<br>
If the issued day exceeds or is equal to the 16th day of the month, then the month increments, the day changes accordingly thus extracting the required due date.<br>


<h3>FINE FUNCTION 💲</h3>
Fine function has a number of conditions as follows<br>
If the number days, after the due date is zero. The fine is zero<br>
If a student has not returned the book , 30 days after the due date, the student is blacklisted.<br>
Amongst the 30 days<br>
Fine for the first five days is 5 rupees<br>
Fine for the next ten days is 10 rupees per day<br>
Fine for the next 15 days is 15 rupees per day<br>
This function calculates the fine according to the due date and charges the student.<br>

<h3>RETURN BOOK FUNCTION 📕</h3>
This function prompts the user to enter the unique id,<br>
If the id exists in the issued book library, it adds the book details to the main library and the return book library<br>
Deletes the book details from the issued book library<br>
If the id does not exist in the issue book library, then an error message is displaying saying so.<br>

<h3>VIEW BORROWED BOOKS FUNCTION 🧾</h3>
This function is used to track which student has issued a particular book<br>
The details of the borrower is displayed upon entering the unique id of the book<br>

<h3>SORT BOOKS ACCORDING TO SEMESTER FUNCTION 🔀</h3>
This function is used to view all the books of a particular semester<br>
Allows the user to enter the particular sem of choice<br>
The book details of all the book belonging to that semester is displayed for the user.<br>

<h3>SORT BOOKS ACCORDING TO AUTHOR FUNCTION ⬇️</h3>
This function categorises books according to the particular author of the users choice<br>
The book details of all the books under that particular author is displayed for the user.<br>
If the author entered by the user is not a part of the library, an error message is displayed saying so<br>



