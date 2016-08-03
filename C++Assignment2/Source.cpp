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

bool User::CheckIfUserExist(string) {

}

void User::UpdateUserList() {

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

