# FUNCTIONALITY

The program provides multiple functions that the user can utilize to manage data, some of which include: 

# ADMIN PANEL FEATURES

•	 Create New Record

The program allows the admin to create records for individual students, sequencing their information with respect to name, roll #, section, batch, department, email, etc. This data is saved permanently in external files.


•	 Modify A Record

The admin can make changes to saved data files of students, like editing or deleting, simply by searching for the file by the student’s roll number.

•	 View Existing Record

The admin can easily access saved records by entering the roll number of a student, which is then compared to existing records and related details are displayed on the screen.


•	Pending Edit Requests

The admin has access to pending edit requests made by students using the Student Panel. These requests contain the roll number and name of the student along with the details to update their record, this can be reviewed by the admin, and required changes can be made. The pending request files can later be deleted when the records are updated.


# STUDENT PANEL FEATURES


•	View My Profile

Students can view their details by entering their roll number. If their file does not exist, they are returned to the main menu.

•	Request Edit

Students can request updates in their details, their requests are saved in separate files, which can be accessed from the admin panel.

# Other features include:

•	Login 

The program allows access to the user when one of the correct usernames and passwords are entered. 
The user is then allowed access to the Admin or Student Panel, which have different features. Moreover, the system only allows limited attempts to login with the correct details.

•	Input Safety

The program features 4 useful functions to safely obtain input from users. These functions restrict the input to desired numbers and characters. 

•	Current Time & Date

The program displays the current time and date at each menu.



•	Delay

The delay function delays the execution of commands by using the internal clock of the system obtained by <ctime> library. It is also used to simulate a loading progress bar.

•	Request Notification

When a user logs into the Admin Panel, the program first searches all possible request files. If new requests exist, a notification is displayed next to the Pending Edit Requests function on the menu.

•	Exit

The program does not terminate on its own, it simply calls the login function whenever the user exits the main menu.


All functions are saved in the Management.h header file.
