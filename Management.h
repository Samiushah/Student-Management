#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;	

void add();
int display_record(char mod);
int login(int tries);
void main_menu_A();
void main_menu_S();
void date_time();
void delay(int i);
void display_(int count);
void display_return1();
void display_return2();
int panel; // used in display_record() to determine if user is an admin or student, and display output accordingly.

//-----------------------INPUT----SAFETY----FUNCTIONS---------------------------//

/* Safely obtains correct integer input.
   Used for choices.                      */

int input_safety1(char A, char B, int l1, int l2)
{
	// A - B specify the range of characters, 
	// l1 specifies minimum length of input.
	// l2 specifies maximum length of input.

	char input[7];
	char a;
	for (int i = 0;;)
	{
		a = _getch();

		// If character a is 'A' - 'B', it is stored in string

		if ((a >= A && a <= B) && i <= l2)
		{
			input[i] = a;
			i++;
			cout << a;

		}

		// If user attempts to remove a character by pressing backspace, it is allowed.

		if (a == '\b' && i >= 1)
		{
			cout << "\b \b";
			i--;
		}

		// If user attempts to add more than a l2 characters (except enter), they are removed.

		 if (i > l2 && a!= '\r')
		{
			cout << "\b \b";
			i--;
		}

		// If user has input at least l1 character and presses enter, the input is accepted and the loop breaks.

		if (i >= l1 && a == '\r')
		{
			input[i] = '\0';
			break;
		}
	}

	// Convert obtained input string into integer

	stringstream str(input);
	int output = 0;
	str >> output;

	return output;
}

/* Safely obtains correct character (alphabets only) input.
   Used for name, section, department, etc.                 */

char* input_safety2(int l1, int l2, char space)
{
	// l1 specifies minimum required characters.
	// l2 specifies maximum required characters.
	// space specifies if " " space character is allowed in input.

    static char input[80]; //Static array
	char a;
	for (int i = 0;;)
	{
		a = _getch();

		// If character a is 'A' - 'Z', it is stored in string.
		
		if (space == 'y')
		{
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a == ' '))
			{
				input[i] = a;
				i++;
				cout << a;
			}
		}
		else
		{
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
			{
				input[i] = a;
				i++;
				cout << a;
			}
		}

			// If user attempts to remove a character by pressing backspace, it is allowed.

			if (a == '\b' && i >= 1)
			{
				cout << "\b \b";
				i--;
			}

			// If user attempts to add more than l2 character (except enter), they are removed.

			if (i > l2 && a != '\r')
			{
				cout << "\b \b";
				i--;
			}

			// If user has input at least l1 character and presses enter, the input is accepted and the loop breaks.

			if (i >= l1 && a == '\r')
			{
				input[i] = '\0';
				break;
			}

	}
	

	return input;
}

/* Safely obtains correct character (alphabets and numbers and special chars) input.
    Used for email.                                               */

char* input_safety3(int l1, int l2, char space)
{
	// l1 specifies minimum required characters
	// l2 specifies maximum required characters.
	// space specifies if " " space character is allowed in input.

	static char input[80]; //Static array
	char a;
	for (int i = 0;;)
	{
		a = _getch();

		// If character a is 'A' - 'Z' or '0' - '9', it is stored in string.

		if (space == 'y')
		{
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == ' ') || (a == '_') || (a == '.') || (a == '@'))
			{
				input[i] = a;
				i++;
				cout << a;
			}
		}
		else
		{
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a == '_') || (a == '.') || (a == '@'))
			{
				input[i] = a;
				i++;
				cout << a;
			}
		}

		// If user attempts to remove a character by pressing backspace, it is allowed.

		if (a == '\b' && i >= 1)
		{
			cout << "\b \b";
			i--;
		}

		// If user attempts to add more than l2 character (except enter), they are removed.

		if (i > l2 && a != '\r')
		{
			cout << "\b \b";
			i--;
		}

		// If user has input at least l1 character and presses enter, the input is accepted and the loop breaks.

		if (i >= l1 && a == '\r')
		{
			input[i] = '\0';
			break;
		}

	}

	return input;
}

/* Safely obtains characters (numbers only) input.
   Used for roll number, phone number, etc.        */

char* input_safety4(int l1, int l2)
{
	// l1 specifies minimum required characters
    // l2 specifies maximum required characters.

	static char input[12]; //Static array
	char a;
	for (int i = 0;;)
	{
		a = _getch();

		// If character a is '0' - '9', it is stored in string.

		if ((a >= '0' && a <= '9'))
		{
			input[i] = a;
			i++;
			cout << a;
		}

		// If user attempts to remove a character by pressing backspace, it is allowed.

		if (a == '\b' && i >= 1)
		{
			cout << "\b \b";
			i--;
		}

		// If user attempts to add more than 11 character (except enter), they are removed.

		if (i > l2 && a != '\r')
		{
			cout << "\b \b";
			i--;
		}

		// If user has input at least 11 character and presses enter, the input is accepted and the loop breaks.

		if (i >= l1 && a == '\r')
		{
			input[i] = '\0';
			break;
		}

	}

	return input;
}

/* Safely obtains correct email address.

string input_safety_mail(int i, string s)
{
		

			if (i == 1)
			{
				string x = "@gmail.com";
				s = s + x;

			}
			else if (i == 2)
			{
				string y = "@yahoo.com";
				s = s + y;
			}
			else
			{
				string z = "@outlook.com";
				s = s + z;
			}

	return s;
} */

//--------------------------------xxxxxxxx------------------------------------//

//---------------------------MISCELLANEOUS----FEATURES------------------------//

// displays current date and time

void date_time()
{
	// current date/time based on current system

	time_t now = time(0);

	tm* ltm = localtime(&now);

	// prints various components of tm structure.

		// day of the month.
	cout << ltm->tm_mday << "/";

	// months since January.
	cout << 1 + ltm->tm_mon << "/";

	// years since 1900.
	cout << 1900 + ltm->tm_year << "\t\t  ";

	if ((1 + ltm->tm_hour) > 12)
	{
		// hours since midnight.
		ltm->tm_hour -= 12;

		cout << ltm->tm_hour << ":" << 1 + ltm->tm_min << " PM";
	}
	else
	{
		cout << ltm->tm_hour << ": " << 1 + ltm->tm_min << " AM";
	}

	cout << endl << endl;
}

// delays stream by comparing processor clock ticks with input.

void delay(int t)
{
	clock_t goal = t + clock();
	while (goal > clock());
}

//---------------------------------xxxxxxxx----------------------------------//


//---------------------------FILING---&---STRUCTURES------------------------//

struct student_info
{
	string roll_no = "111";
	string name = "default";
	string dept = "xx";
	int batch = 2000;
	string section = "x";
	string phone_no = "03xxxxxxxxx";
	string email = "xxx@xxx.com";
};

// structure variable.

struct student_info c;

// adds new records.

void add()
{
	cout << "\n \t\t\t\t\t  ";
	date_time();
	cout << "\t\t\t  ------------------------------------------------------------------- \n";
	cout << "\t\t\t  |                         CREATE RECORD                           | \n";
	cout << "\t\t\t  ------------------------------------------------------------------- \n\n";
	cout << "\t\t\t\t         Select slot# (1-999) to save user data: \n";
	cout << "\t\t\t    (Note: Selecting an occupied slot will overwrite existing data) \n\n";
	cout << "\t\t\t\t\tSLOT: ";

	// strings to obtain correct file name.

	string x = "0";

		x = input_safety4(1, 3);
		if (x == "0")
		{
			cout << "\n\n\t\t\t\t\t     Invalid slot entry, try again. \n\n";
			delay(1500);
			system("cls");
			add();
		}

	string a = "user";
	string b = ".txt";
	string Z = a + x + b; // example: user1.txt
	
	cout << "\n\n\t\t\t\t\tROLL#: ";
	c.roll_no = input_safety4(1,3); //roll number (1-3 digits)

	cout << "\n\n\t\t\t\t\tNAME: ";
	c.name = input_safety2(8, 45, 'y'); //name (8-45 length including spaces)

	cout << "\n\n\t\t\t\t\tDEPT: ";
	c.dept = input_safety2(2, 2,'n'); //dept (2 length not including spaces)

	cout << "\n\n\t\t\t\t\tBATCH: 20";
	c.batch = input_safety1('0', '9', 2, 2); //batch (2 digits)
	c.batch += 2000; // example: 19 += 2000 >>> 2019

	cout << "\n\n\t\t\t\t\tSECTION: ";
	c.section = input_safety2(1, 1,'n'); //section (1 length not including spaces)

	cout << "\n\n\t\t\t\t\tEMAIL: ";
	c.email = input_safety3(15,30, 'n'); //email (15-30 length not including spaces)

	/*cout << "\n\n \t\t\t\t\t     1) gmail.com";
	cout << "\n\n \t\t\t\t\t     2) yahoo.com";
	cout << "\n\n \t\t\t\t\t     3) outlook.com \n\n \t\t\t\t\t        (1/2/3)  ";
	int option = input_safety1('1', '3', 1, 1);
	c[y - 1].email = input_safety_mail(option, c[y - 1].email);*/

	cout << "\n\n \t\t\t\t\tCELL#: ";
	c.phone_no = input_safety4(11,11); //cell# (11 digits)


	// Filing instance

			ofstream user; //output file stream - Create files and to write to files.

			user.open(Z); //example: z = user1.txt

			if (user.is_open()) //writing to file, adding new line character to organize information for convenience.
			{
				user << c.roll_no << "\n";
				user << c.name << "\n";
				user << c.dept << "\n";
				user << c.batch << "\n";
				user << c.section << "\n";
				user << c.phone_no << "\n";
				user << c.email << "\n";

				user.close();

			}


	cout << "\n\n\n\t\t\t\t\t    ";
	cout << "|Record Successfully Added|";
	delay(1500);
	system("cls");

	display_return1(); // display menu options
}

// edits and deletes saved records.

void modify()	
{
	int choice;
	cout << "\n\n\n\n\n \t\t\t\t\t ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
    cout << "\t\t\t\t\t|         MODIFY RECORD          | \n";
    cout << "\t\t\t\t\t---------------------------------- ";
	cout << "\n\n\t\t\t\t\t1) Edit Record. \n\n";
	cout << "\t\t\t\t\t2) Delete Record. \n\n\n";
	cout << "\t\t\t\t\t         (1/2): ";
	choice = input_safety1('1', '2', 1, 1);
	system("cls");

	int fileno = display_record('y'); //obtains file number of displayed record.

	// file number integer is converted to string, so it can be concatenated to string Z.

	string x = to_string(fileno); //to_string() is a predefined function included in <string> header file
	string a = "user";
	string b = ".txt";
	string Z = a + x + b; // example: user1.txt

	cout << "\n\n\n\n\n \t\t\t\t\t ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
	cout << "\t\t\t\t\t|         MODIFY RECORD          | \n";
	cout << "\t\t\t\t\t---------------------------------- \n\n";

	if (choice == 1)
	{
		cout << "\t\t\t\t   Are you sure you want to edit this record? \n\n";
		cout << "\t\t\t\t\t    1) Yes. \n\n\t\t\t\t\t    2) No.";
		cout << "\n\n\t\t\t\t\t           (1/2): ";
		int sure = input_safety1('1', '2', 1, 1);

		if (sure == 2)
		{
			system("cls");
			display_return2();
		}
		else
		{
			fstream user; //input/output file stream - read from files/write to files.
			string l; // string to store each line of file one by one.
			int count = 0; // integer to ensure organized transfer of string from l to structure items.
			user.open(Z); //example: user1.txt

			if (user.is_open())
			{
				while (getline(user, l)) //reading from file line by line, storing each line in l and copying string from l to structure items.
				{
					if (count == 0)
					{
						c.roll_no = l;
					}
					else if (count == 1)
					{
						c.name = l;
					}
					else if (count == 2)
					{
						c.dept = l;
					}
					else if (count == 3)
					{
						// converting string l to y and stores in structure item

						stringstream str(l); //stringstream is a predefined function included in <sstream> header file.
						int y = 0;
						str >> y;

						c.batch = y;
					}
					else if (count == 4)
					{
						c.section = l;
					}
					else if (count == 5)
					{
						c.phone_no = l;
					}
					else if (count == 6)
					{
						c.email = l;
					}

					count++;
				}

				user.close();
			}

			system("cls");

			cout << "\n\n\n\n\n \t\t\t\t\t ";
			date_time();
			cout << "\t\t\t\t\t---------------------------------- \n";
			cout << "\t\t\t\t\t|         MODIFY RECORD          | \n";
			cout << "\t\t\t\t\t---------------------------------- \n\n";

			cout << "\t\t\t\t\t Select field to edit: \n\n";
			cout << "\t\t\t\t\t 1) ROLL# \n\t\t\t\t\t 2) NAME \n\t\t\t\t\t 3) DEPT";
			cout << "\n\t\t\t\t\t 4) BATCH \n\t\t\t\t\t 5) SECTION \n\t\t\t\t\t 6) CELL#";
			cout << "\n\t\t\t\t\t 7) EMAIL \n\n\t\t\t\t\t";
			cout << "         (1/2/3/4/5/6/7): ";
			int edit = input_safety1('1', '7', 1, 1);
			cout << "\n\n\t\t\t\t\t Enter edited information: ";

			switch (edit) // editing user desired info.
			{

				// all structure items assigned default "0" value
				// to avoid overwriting

			case 1: c.roll_no = "0";
				c.roll_no = input_safety4(1, 3);
				break;
			case 2: c.name = "0";
				c.name = input_safety2(3, 45, 'y');
				break;
			case 3: c.dept = "0";
				c.dept = input_safety2(2, 2, 'n');
				break;
			case 4: cout << "20";
				c.batch = 0;
				c.batch = input_safety1('0', '9', 2, 2);
				c.batch += 2000;
				break;
			case 5: c.section = "0";
				c.section = input_safety2(1, 1, 'n');
				break;
			case 6: c.phone_no = "0";
				c.phone_no = input_safety4(11, 11);
				break;
			case 7: c.email = "0";
				c.email = input_safety3(4, 30, 'n');
				break;
			}

			user.open(Z);

			if (user.is_open()) // writing info back to file in order, including edited info.
			{
				user << c.roll_no << "\n";
				user << c.name << "\n";
				user << c.dept << "\n";
				user << c.batch << "\n";
				user << c.section << "\n";
				user << c.phone_no << "\n";
				user << c.email << "\n";

				user.close();

			}

			cout << "\n\n\t\t\t\t\t   |Record edited successfully!| ";
			delay(2500);
			system("cls");
			main_menu_A();
		}

	}
	else if (choice == 2)
	{
		cout << "\t\t\t\t   Are you sure you want to delete this record? \n\n";
		cout << "\t\t\t\t\t    1) Yes. \n\n\t\t\t\t\t    2) No.";
		cout << "\n\n\t\t\t\t\t           (1/2): ";
		int sure = input_safety1('1', '2', 1, 1);

		if (sure == 2)
		{
			system("cls");
			main_menu_A();
		}

		else
		{
			// deleting file. 

			char removef[40];
			strcpy(removef,Z.c_str()); // copying string Z to char array removef as remove() doesn't accept strings.
			                           // c_str() is a predefined function in <string> header file.
			remove(removef); //remove() is apredefined function in <cstdio> header file.	
		}

		cout << "\n\n\t\t\t\t\t   |Record removed successfully!| ";
		delay(2500);
		system("cls");
		display_return2();
	}

	system("cls");

}

// displays saved records.

int display_record(char mod)
{
	// if mod != 'n', this function does not call main menu,
	// and returns the file number to modify function.

	string check1; // string to check if roll# is in opened file.
	bool check = false; //boolean value is false till roll no is located in anyone of the opened files.
	string file = "x"; // default file number.
	cout << "\n\n\n\n\n \t\t\t\t\t ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
	cout << "\t\t\t\t\t|         STUDENT RECORD         | \n";
	cout << "\t\t\t\t\t---------------------------------- \n\n";
	cout << "\t\t\t\t\t Enter Roll#: ";
	check1 = input_safety4(1,3), cout << "\n\n \t\t\t\t\t";

	string x = "1";
	string a = "user";
	string b = ".txt";
	string Z;
	int y = 1;

	for (int i = 0; i < 999; i++) //checks all possible files till correct file is found.
	{
		Z = a + x + b; // example: user1.txt
		ifstream user; //input file stream - Read from files.
		string l; // string to store each line of file one by one.
		int count = 0;
		user.open(Z);

		if (user.is_open())
		{
			while (getline(user, l))
			{
				if (l == check1) // if (line == roll no)
				{
					check = true;
					file = x; //file number 'x' is copied to string file.
				}

				if (check)
				{
					display_(count); //displays title for file info
					cout << l; //displays info
					count++;
				}

			}
			user.close();

		}

		if (check)
		{
			cout << "\n\n\n\t\t\t\t\t Press any key to continue...\n\n";
			getch(); //pauses screen till a key is pressed.
			system("cls");
			break;
		}

		// integer y is incremented so it can be converted to string x
		// to update file name.

		y++;
		x = to_string(y);
	}
		if (panel == 2 && !check) //if user is a student.
		{
			cout << "\n\n\t\t\t\t\t   > Record not found";
		    cout << "\n\n\t\t\t\t\t   > Please contact admin";
			delay(2500);
			system("cls");
		}
		else if (!check) //if user is an admin.
		{
			cout << "\n\n\t\t\t\t\t     > Record not found \n\n";
			delay(2500);
			system("cls");
		}
	
	
	if (mod == 'n') //file is not to be modified.
	{
		if (panel == 2)
		{
			main_menu_S();
		}
		else
		{
			main_menu_A();
		}
	}

	//file is to be modified, returns file number to modify function.

	return y;

}

// Saves edit requests by students .

void requests_S()
{
	string roll;
	string name;
	string edit;
	cout << "\n\n\n\n\n \t\t\t\t        ";
	date_time();
	cout << "\t\t\t  ------------------------------------------------------------------- \n";
	cout << "\t\t\t  |                        REQUEST AN EDIT                          | \n";
	cout << "\t\t\t  ------------------------------------------------------------------- \n\n";
	cout << "\t\t\t\t\tSelect slot (1-9): ";
	int slot = input_safety1('1','9',1, 1);
	cout << "\n\n\t\t\t\t\t\tROLL#: ";
	roll = input_safety4(1, 3);
	cout << "\n\n\t\t\t\t\t\tNAME: ";
	name = input_safety2(3, 40, 'y');
	cout << "\n\n\t\t\t\t  Specify the information that you want to be edited: \n\n\t\t\t\t  ";
	edit = input_safety3(3,70,'y'), cout << "\n\n";

	ofstream user; //output file stream - Creates files / Writes to files.
	string l;
	string a = to_string(slot);
	string x = "requests";
	string y = ".txt";
	string z = x + a + y; // example: requests1.txt

	user.open(z);
	
		if (user.is_open()) //writing to file, adding new line character to organize information for convenience.
		{
			user << roll << "\n";
			user << name << "\n";
			user << edit << "\n";

			cout << "\t\t\t Your request has been submitted and will be reviewed by an admin. \n\n";
		}

		user.close();


	

	delay(2500);
	system("cls");
	main_menu_S();
}

// displays requests by students.

void requests_A(int pending)
{
	string roll;
	string name;
	string edit;
	cout << "\n\n\n\n\n \t\t\t\t        ";
	date_time();
	cout << "\t\t\t  ------------------------------------------------------------------- \n";
	cout << "\t\t\t  |                           EDIT REQUESTS                         | \n";
	cout << "\t\t\t  -------------------------------------------------------------------";

	if (pending < 1)
	{
		cout << "\n\n\t\t\t\t\t > There are no pending requests.";
		delay(1500);
		system("cls");
		main_menu_A();
	}
	else
	{
		ifstream user; // input file stream - Reads from files.
		string l;
		int count = 0;
		string x = "requests";
		string y = ".txt";
		string z;
		string temp = "0"; // default file number.
		int i;
		int n[9]; // to store actual file number.

		cout << "\n\n\t\t\t\t NEW REQUESTS: ";

		for (i = 0; i < 9; i++) // Reads all possible files to check if first line contains a character
			                    // If first line contains a character, the file is displayed as a pending request.
		{
			temp = to_string(i); // converting integer i to string.
			z = x + temp + y; // example: requests1.txt

			user.open(z);

			if (user.is_open())
			{
				while (getline(user, l))
				{
					if (l > "0")
					{
						cout << "\n\n\t\t\t\t > Slot# " << i;
						n[i] = i;
						break;
					}
				}

				user.close();
			}
		}

		cout << "\n\n\n\t\t\t\t\t Select a request to view/edit. \n\n";
		cout << "\t\t\t\t\t > ";
		int choice = input_safety1('1', '9', 1, 1);

		if (choice > i) // if input is greater than existing file requests.
		{
			cout << "\n\n\t\t\t\t\t       Please try again. \n\n";
			delay(1500);
			system("cls");
			requests_A(pending);
		}
		else if ((choice == n[0]) || (choice == n[1]) || (choice == n[2]) || (choice == n[3]) || (choice == n[4]) || (choice == n[5]) || (choice == n[6]) || (choice == n[7]) || (choice == n[8]))
		{
			system("cls");

			cout << "\n\n\n\n\n \t\t\t\t        ";
			date_time();
			cout << "\t\t\t  ------------------------------------------------------------------- \n";
			cout << "\t\t\t  |                           EDIT REQUESTS                         | \n";
			cout << "\t\t\t  -------------------------------------------------------------------\n";

			temp = to_string(choice); // convert integer choice to string.
			z = x + temp + y;

			ifstream user;
			user.open(z);

			if (user.is_open())
			{
				while (getline(user, l)) //reads and displays information line by line.
				{
					cout << "\n\t\t\t\t\t\t> " << l << "\n";
				}
				user.close();
			}

			int continue_;

			cout << "\n\t\t\t\t\t\tContinue: \n\n";
			cout << "\t\t\t\t\t\t  1) Modify Records \n\t\t\t\t\t\t  2) Delete Request\n\n";
			cout << "\t\t\t\t\t\t    (1/2): ", continue_ = input_safety1('1', '2', 1, 1);

			if (continue_ == 1)
			{
				system("cls");
				modify();
			}
			else
			{
				char removef[40];
				strcpy(removef, z.c_str()); // copying string Z to char array removef as remove() doesn't accept strings.
			                           // c_str() is a predefined function in <string> header file.
				remove(removef); //remove() is apredefined function in <cstdio> header file.	

				cout << "\n\n\t\t\t\t\t     > |Request has been deleted| ";
				delay(1500);
				system("cls");
				main_menu_A();
			}
		}
		else
		{
			cout << "\n\n\t\t\t\t\t       Please try again. \n\n";
			delay(1500);
			system("cls");
			requests_A(pending);
		}
	}
}

// Notifies about pending edit requests on admin menu.

int requests_notif()
{
	ifstream user;
	string l;
	int count = 0;
	string x = "requests";
	string y = ".txt";
	string z;
	string temp;

	for (int i = 0; i < 9; i++)
	{

		temp = to_string(i);
		z = x + temp + y;

		user.open(z);

		if (user.is_open())
		{
			while (getline(user, l))
			{
				if (l > "0")
				{
					count++;
					break;
				}
			}

			user.close();
		}
	}

	return count;
}

//---------------------------------xxxxxxx------------------------------------//


//-----------------------------LOGIN---&---MENU-------------------------------//

// login allows 3 attempts to input correct details,
// compares input with hardcoded details,
// and allows/denies access after comparison

int login(int tries)
{
	string usern;
	char pass[20];

	cout << "\n\n\n\n\n \t\t\t\t        ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
	cout << "\t\t\t\t\t|             LOGIN              | \n";
	cout << "\t\t\t\t\t---------------------------------- \n\n";
	cout << "\t\t\t\t\t     USERNAME: ";
	usern = input_safety3(2,10,'n'), cout << "\n\n";
	cout << "\t\t\t\t\t     PASSWORD: ";

	// password privacy - START

	char a;

	for (int i = 0;;)
	{
		a = _getch(); //conio.h predefined function to pause the screen till user hits a key.

		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		{
			pass[i] = a;
			i++;
			cout << "*";
		}
		if (a == '\b' && i >= 1)
		{

			cout << "\b \b";
			i--;
		}
		if (a == '\r')
		{
			pass[i] = '\0';
			break;
		}
	}

	// password privacy - END

	cout << "\n\n\t\t\t\t\t     LOADING";

	for (int i = 0; i < 15; i++)
	{
		delay(100);
		cout << ".";
	}

	// clears command promt screen.

	system("cls");

	if (((usern == "sami") || (usern == "asad") || (usern == "shayan") || (usern == "alyan") || (usern == "quratulain")) && strcmp(pass, "cpps") == 0)
	{
		panel = 1; // used in display_record() to determine output display.
		cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t\t------------------- \n";
		cout << "\t\t\t\t\t\t  WELCOME, ADMIN \n";
		cout << "\t\t\t\t\t\t------------------- ";
		delay(2000);
		system("cls");
		main_menu_A();
	}
	else if ((usern == "student") && strcmp(pass, "abc123") == 0)
	{
		panel = 2; // used in display_record() to determine output display.
		cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t\t--------------------- \n";
		cout << "\t\t\t\t\t\t  WELCOME, STUDENT \n";
		cout << "\t\t\t\t\t\t--------------------- ";
		delay(2000);
		system("cls");
		main_menu_S();

	}
	else
	{
		if (tries > 0)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t";
			cout << "Incorrect details, please try again. (" << tries << ")";
			delay(2000);
			system("cls");
			return login(tries - 1);
		}
		else
		{
			cout << "\n\n\n\n\n\n\n\n\n \t\t\t\t\t";
			cout << "Incorrect details. Please consult an admin. \n\n\n\n\n\n\n";
		}
	}

	return 0;
}

// displays menu for admin.

void main_menu_A()
{
	int pending = requests_notif();
	cout << "\n\n\n\n\n \t\t\t\t        ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
	cout << "\t\t\t\t\t|   STUDENT MANAGEMENT  SYSTEM   | \n";
	cout << "\t\t\t\t\t---------------------------------- \n \t\t\t\t\t| \t\t\t\t | \n";

	for (int i = 0; i < 13; i++)
	{
		cout << "\t\t\t\t\t|";

		switch (i)
		{
		case 0: cout << "        SELECT AN OPTION        |\n";
			break;
		case 2: cout << "   1. Create New Record.        |\n";
			break;
		case 4: cout << "   2. Modify Existing Record.   |\n";
			break;
		case 6: cout << "   3. View Existing Record.     |\n";
			break;
		case 8: cout << "   4. Pending Edit Requests";
			    if (pending > 0)
			    {
				cout << " (" << pending << ") |\n";
			    }
				else
				cout << ".    |\n";
			break;
		case 10: cout << "   5. Exit.                     |\n";
			break;
		case 12: cout << "________________________________|\n";
			break;
		}

		if (i % 2 == 1)
		{
			cout << "                                |\n";
		}
	}

	cout << "\n\t\t\t\t\t\t (1/2/3/4/5): ";

	int x = input_safety1('1','5',1,1);

		delay(300);

		// clears command promt screen.

		system("cls");

		// Obtained integer passed to switch statement.

		switch (x)
		{
		case 1: add();
			break;
		case 2: modify();
			break;
		case 3: display_record('n');
			break;
		case 4: requests_A(pending);
			break;
		case 5: cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t     ------------------------- \n";
			cout << "\t\t\t\t\t      LOGGED OUT SUCCESSFULLY \n";
			cout << "\t\t\t\t\t     -------------------------";
			delay(2500);
			system("cls");
			login(2);
			break;
		}


}

// displays menu for students.

void main_menu_S()
{
	cout << "\n\n\n\n\n \t\t\t\t        ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
	cout << "\t\t\t\t\t|   STUDENT MANAGEMENT  SYSTEM   | \n";
	cout << "\t\t\t\t\t---------------------------------- \n \t\t\t\t\t| \t\t\t\t | \n";

	for (int i = 0; i < 9; i++)
	{
		cout << "\t\t\t\t\t|";

		switch (i)
		{
		case 0: cout << "        SELECT AN OPTION        |\n";
			break;
		case 2: cout << "   1. View My Profile.          |\n";
			break;
		case 4: cout << "   2. Request Edit.             |\n";
			break;
		case 6: cout << "   3. Exit.                     |\n";
			break;
		case 8: cout << "________________________________|\n";
			break;
		}

		if (i % 2 == 1)
		{
			cout << "                                |\n";
		}
	}

	cout << "\n\t\t\t\t\t\t   (1/2/3): ";

	int x = input_safety1('1', '3', 1, 1);

	delay(300);

	// clears command promt screen.

	system("cls");

	// Obtained integer passed to switch statement.

	switch (x)
	{
	case 1: display_record('n');
		break;
	case 2: requests_S();
		break;
	case 3: cout << "\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t     ------------------------- \n";
		cout << "\t\t\t\t\t      LOGGED OUT SUCCESSFULLY \n";
		cout << "\t\t\t\t\t     -------------------------";
		delay(2500);
		system("cls");
		login(2);
		break;
	}

}

//---------------------------------xxxxxxx-----------------------------------//

//------------------------------DISPLAY----FUNCTIONS----------------------------//

// Displays options to return to menu / add another record.

void display_return1()
{
	cout << "\n\n\n\n\n \t\t\t\t        ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
	cout << "\t\t\t\t\t|             SELECT             | \n";
	cout << "\t\t\t\t\t---------------------------------- \n \t\t\t\t\t| \t\t\t\t | \n";

	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t\t\t\t|";

		switch (i)
		{
		case 0: cout << "   1. Create Another Record.    |\n";
			break;
		case 2: cout << "   2. Return To Main Menu.      |\n";
			break;
		case 4: cout << "________________________________|\n";
			break;
		}

		if (i % 2 == 1)
		{
			cout << "                                |\n";
		}
	}

	cout << "\n\t\t\t\t\t\t      (1/2): ";

	int y = input_safety1('1', '2', 1, 1);

	delay(300);

	if (y == 1)
	{
		system("cls");
		add();
	}
	else
	{
		system("cls");
		main_menu_A();
	}
}

// Displays options to return to menu / modify another record.

void display_return2()
{
	cout << "\n\n\n\n\n \t\t\t\t        ";
	date_time();
	cout << "\t\t\t\t\t---------------------------------- \n";
	cout << "\t\t\t\t\t|             SELECT             | \n";
	cout << "\t\t\t\t\t---------------------------------- \n \t\t\t\t\t| \t\t\t\t | \n";

	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t\t\t\t|";

		switch (i)
		{
		case 0: cout << "   1. Modify Another Record.    |\n";
			break;
		case 2: cout << "   2. Return To Main Menu.      |\n";
			break;
		case 4: cout << "________________________________|\n";
			break;
		}

		if (i % 2 == 1)
		{
			cout << "                                |\n";
		}
	}

	cout << "\n\t\t\t\t\t\t      (1/2): ";

	int y = input_safety1('1', '2', 1, 1);

	delay(300);

	if (y == 1)
	{
		system("cls");
		modify();
	}
	else
	{
		system("cls");
		main_menu_A();
	}
}

// Displays titles for file info.

void display_(int count)
{
	if (count == 0)
	{
		cout << "\n\n\t\t\t\t\tROLL#: ";
	}
	if (count == 1)
	{
		cout << "\n\n\t\t\t\t\tNAME: ";
	}
	if (count == 2)
	{
		cout << "\n\n\t\t\t\t\tDEPT: ";
	}
	if (count == 3)
	{
		cout << "\n\n\t\t\t\t\tBATCH: ";
	}
	if (count == 4)
	{
		cout << "\n\n\t\t\t\t\tSECTION: ";
	}
	if (count == 5)
	{
		cout << "\n\n\t\t\t\t\tCELL#: ";
	}
	if (count == 6)
	{
		cout << "\n\n\t\t\t\t\tEMAIL: ";
	}
}

// Display title

void displayT()
{
	cout << "\n\n\n========================================================================================================================";
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t    ---------------------------------- \n";
	cout << "\t\t\t\t\t    |  *STUDENT MANAGEMENT SYSTEM*   | \n";
	cout << "\t\t\t\t\t    ---------------------------------- \n\n";
	cout << "\t\t\t\t\t         >>>> SAMI ULLAH SHAH <<<<";
	cout << "\n\n\n\n========================================================================================================================";

	cin.get();
	system("cls");
}


//-----------------------------------xxxxxxxx----------------------------------//