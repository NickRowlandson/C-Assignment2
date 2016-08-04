#include "Header.h"

User user1;
HighScoreManager score1;

// HIGHSCOREMANAGER CLASS METHODS
void HighScoreManager::CreateHighScore() {
	//FUNCTION NOT REQUIRED
}

void HighScoreManager::UpdateHighScore() {
	//FUNCTION NOT REQUIRED
}

void HighScoreManager::PrintHighScore() {
	UpdateScoreVector();
	int line2;
	// for each record in the vector, check if it is equal to the entered username
	for (int i = 0; i < lines2.size(); i++)
	{
		cout << lines2[i] << endl;
	}

	// LOOP THROUGH DAT FILE AND PRINT TABLE OF HIGH SCORES
}

// USER CLASS METHODS
void User::Login() {
	string user;
	cout << "WELCOME TO: High Score Manager!" << endl
		<< "Enter your username: ";
	cin >> user;
	cin.ignore();

	if (!user1.CheckIfUserExist(user))
	{
		ofstream out;
		// append new user name and empty score to names.txt
		out.open("names.txt", ios::app);

		out << endl << user;
		out << endl << "Full Name: " ;
		out << endl << "Score: ";

		cout << "Welcome, " + user1.username + "!" << endl;
	}
	else
	{
		cout << "Welcome back, " + user1.username + "!" << endl;
	}
}

bool User::CheckIfUserExist(string user) {
	user1.username = user;
	bool userFound = false;
	bool endLoop = true;
	ifstream file("names.txt");
	string name;

	// loop through names.txt
	while (getline(file, name) && endLoop)
	{
		// if there is already user in names.txt, display previous score and set oldScore global variable
		if (name.find(username) != string::npos)
		{
			userFound = true;
			endLoop = false;
		}
	}

	// if no user is found, display welcome message and return false
	if (!userFound)
	{
		return false;
	}
	// if user found, display welcome back message and return true
	else 
	{
		return true;
	}
}

void User::UpdateUserVector() {
	// clear elements in vector
	lines.clear();
	// open file stream
	ifstream file("names.txt");

	string line;
	// add each line in names.txt to the vector
	while (getline(file, line))
	{
		if (!line.empty())
		{
			lines.push_back(line);
		}
	}
}
void HighScoreManager::UpdateScoreVector() {
	// clear elements in vector
	lines2.clear();
	// open file stream
	ifstream file("highScore.dat");

	string line2;
	// add each line in names.txt to the vector
	while (getline(file, line2))
	{
		if (!line2.empty())
		{
			lines2.push_back(line2);
		}
	}
}

// View user info
void User::ViewUserInfo() {
	user1.UpdateUserVector();

	bool found = false;
	int line;

	// for each record in the vector, check if it is equal to the current user
	for (int i = 0; i < lines.size(); i++)
	{
		if (user1.username == lines[i])
		{
			line = i;
			found = true;
		}
	}

	cout << endl 
		 << "YOUR INFORMATION:" << endl
		 << "Username: " + lines[line + 0] << endl
		 << lines[line + 1] << endl
		 << "Highscore: " + lines[line + 2] << endl;

}

// Delete user
bool User::DeleteUser() {
	user1.UpdateUserVector();

	string userName;
	bool found = false;

	cout << "Enter the username you want to delete: ";
	cin >> userName;

	if (userName == user1.username) {
		string response;
		cout << "Are you sure you want to delete yourself?(y/n): ";
		cin >> response;

		if (response == "y" || response == "Y" || response == "yes") {

		}
		else if (response == "n" || response == "N" || response == "no") {
			cout << "You chose not to delete yourself. Returning to menu." << endl;
			return true;
		}
		else {
			cout << "You entered an invalid response. Returning to menu." << endl;
			return true;
		}
	}

	int line;

	// for each record in the vector, check if it is equal to the entered username
	for (int i = 0; i < lines.size(); i++)
	{
		if (userName == lines[i])
		{
			line = i;
			found = true;
		}
	}

	// set specific lines in vector to null
	lines[line] = "";
	lines[line+1] = "";
	lines[line+2] = "";

	ofstream outputFile;

	outputFile.open("names.txt");

	// overwrite names.txt with updated vector
	for (int count = 0; count < lines.size(); count++)
	{
		outputFile << lines[count] << endl;
	}

	outputFile.close();

	if (!found) { // x was set to 0 at start, so if it didn't change, it means user entered the wrong name
		cout << "The username you entered does not exist." << endl;
		return true;
	}
	else { // x is not 0, it means user entered the correct name, print message that user data has been deleted
		cout << "User data has been deleted." << endl;
		if (userName == user1.username) {
			return false;
		}
		else {
			return true;
		}
	}
}

// UPDATE name to new name
void User::UpdateUserInfo() {
	user1.UpdateUserVector();

	int line;
	string fname, lname;
	bool found = false;

	user1.UpdateUserVector();

	cout << endl << "Enter you first name: ";
	cin >> fname;
	cout << endl << "Enter you last name: ";
	cin >> lname;

	user1.firstNameLastName = fname + " " + lname;

	// for each record in the vector, check if it is equal to the entered username
	for (int i = 0; i < lines.size(); i++)
	{
		if (user1.username == lines[i])
		{
			line = i;
			found = true;
		}
	}
	
	if (found) {
		// set specific lines in vector to null
		lines[line + 1] = "Full Name: " + user1.firstNameLastName;

		ofstream outputFile;

		outputFile.open("names.txt");

		// overwrite names.txt with updated vector
		for (int count = 0; count < lines.size(); count++)
		{
			outputFile << lines[count] << endl;
		}

		outputFile.close();

		cout << "User info updated successfully!" << endl;
	}
	else {
		cout << "Uh-oh... Something went wrong!" << endl;
	}
}

void User::SetHighScore() {
	int newScore;
	bool cont = true;
	bool found = false;

	while (cont) {
		cout << endl << "Enter your new high score: ";
		cin >> newScore;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (newScore > 1000 || newScore < 0)
		{
			cout << endl << "Invalid input. Please enter an integer between 0 and 1000";
			cont = true;
		}
		else {
			cont = false;
			cout << endl << "New High Score set to: " << newScore;
		}
	}

	string scoreString = to_string(newScore);
	
	// UPDATE TXT FILE
	user1.UpdateUserVector();
	int line;
	// for each record in the vector, check if it is equal to the entered username
	for (int i = 0; i < lines.size(); i++)
	{
		if (user1.username == lines[i])
		{
			line = i;
			found = true;
		}
	}
	// set specific lines in vector to new score
	lines[line + 2] = scoreString;
	ofstream outputFile;
	outputFile.open("names.txt");
	// overwrite names.txt with updated vector
	for (int count = 0; count < lines.size(); count++)
	{
		outputFile << lines[count] << endl;
	}
	outputFile.close();

	// UPDATE DAT FILE
	score1.UpdateScoreVector();
	int line2;
	// for each record in the vector, check if it is equal to the entered username
	for (int i = 0; i < lines2.size(); i++)
	{
		if (user1.username == lines2[i])
		{
			line2 = i;
			found = true;
		}
		else {
			line2 = i;
		}
	}
	if (found) 
	{
		// set specific lines in vector to new score
		lines2[line2 + 1] = scoreString;
		ofstream outputFile;
		outputFile.open("highScore.dat");
		// overwrite highScore.dat with updated vector
		for (int count = 0; count < lines.size(); count++)
		{
			outputFile << lines[count] << endl;
		}
		outputFile.close();
	}
	else 
	{
		lines2.push_back(user1.username);
		lines2.push_back(scoreString);
	}
}


// MAIN
int main(){
	int selection;
	bool cont = true;
	
	user1.Login();
	user1.UpdateUserVector();

	while (cont)
	{
		cout << endl << "Menu" << endl
			<< "1. Enter your new high score" << endl
			<< "2. View your information" << endl
			<< "3. Update your information" << endl
			<< "4. Delete information" << endl
			<< "5. Print all high scores" << endl
			<< "6. Exit" << endl
			<< "Enter your selection number: ";
		cin >> selection;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (selection == 1) {
			user1.SetHighScore();
			cont = true;
			cout << endl << "HIGH SCORE UPDATED" << endl;
		}
		else if (selection == 2) {
			user1.ViewUserInfo();
			cont = true;
		}
		else if (selection == 3) {
			user1.UpdateUserInfo();
			cont = true;
		}
		else if (selection == 4) {
			if (user1.DeleteUser()){
				cont = true;
			}else{
				cout << "You've deleted yourself! Program terminating. Press enter to accept." << endl;
				cin.ignore();
				if (cin.get() == '\n') {
					cont = false;
				}
				else {
					cont = false;
				}
			}
		}
		else if (selection == 5) {
			score1.PrintHighScore();
			cont = true;
		}
		else if (selection == 6) {
			cout << "Thank you for using High Score Manager.";
			cont = false;
		}
		else {
			cout << "ERROR! Invalid Selection. Please enter a number between 1 and 5.";
			cont = true;
		}
	} //ENDWHILE
	
};

