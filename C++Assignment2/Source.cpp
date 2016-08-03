#include "Header.h"

// HIGHSCOREMANAGER CLASS METHODS
void HighScoreManager::CreateHighScore() {

}

void HighScoreManager::UpdateHighScore() {

}


void HighScoreManager::PrintHighScore() {

}

// USER CLASS METHODS
void User::Login() {

}

void User::CheckIfUserExist(string username) {
	currentUser = username;
	bool userFound = false;
	bool endLoop = true;

	// write questions from quiz.txt
	ifstream file("names.txt");
	string name;
	// loop through names.txt
	while (getline(file, name) && endLoop)
	{
		// if there is already user in names.txt, display previous score and set oldScore global variable
		if (name.find(username) != string::npos)
		{
			cout << "Welcome back, " + currentUser + "!" << endl;
			userFound = true;
			endLoop = false;
		}
	}

	// if no user is found, append new user to names.txt
	if (!userFound)
	{
		cout << "Welcome, " + currentUser + "!" << endl;
		ofstream out;

		// append new user name and empty score to names.txt
		out.open("names.txt", ios::app);

		out << endl << username;
		out << endl << 0;
		out << endl << 0;
		out << endl << 0;
		out << endl << 0;
	}
}

void User::UpdateUserList() {
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

void User::DeleteUser() {

}

void User::SetHighScore() {

}


// MAIN
int main(){
	User user1;
	string user;
	cout << "WELCOME TO: High Score Manager!" << endl;
	cout << "Enter your username: ";
	cin >> user;

	user1.CheckIfUserExist(user);
	
};

