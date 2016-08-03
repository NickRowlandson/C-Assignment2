#ifndef HEADER_H
#define HEADER_H

// HighScoreManager class
class HighScoreManager {
public:
	HighScoreManager();
	void CreateHighScore();
	void UpdateHighScore();
	void PrintHighScore();

private:
	string username;
	int score;
	string date;
};

// User class
class User {
public:
	User();
	void Login();
	void CheckIfUserExist();
	void UpdateUserList();
	void DeleteUser();
	void SetHighScore();

private:
	string username;
	string firstNameLastName;
};

#endif