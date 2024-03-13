#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//Function Prototype
int check_password(char* password);

// Function to check the strength of a password
int check_password(char* password) {
	int points;
	int length = strlen(password);
	
	// Scoring for password length
	int lengthScore = (length >= 8) ? 2 : 0;
	int lowercaseScore = 0;
	int uppercaseScore = 0;
	int symbolScore = 0;
	int consecutivenumericScore = 0;

	// Loop through each character in the password
	for (int i = 0; i < strlen(password);i++) {
		// Check if the character is an uppercase letter
		if (isupper(password[i])) {
			uppercaseScore = 2;
		}
		// Check if the character is a lowercase letter
		else if (islower(password[i])) {
			lowercaseScore = 2;
		}
		// Check if the character is a punctuation symbol
		else if (ispunct(password[i])) {
			symbolScore = 2;
		}
		// Check if the character is a digit
		else if (isdigit(password[i])) {
			// Check for consecutive numeric characters
			if (i < length - 2 && isdigit(password[i + 1]) && isdigit(password[i + 2])) {
				consecutivenumericScore = 0;
				break;
			}
			consecutivenumericScore = 1;
		}
	}

	// Calculate total points based on different criteria
	points = lengthScore + uppercaseScore + lowercaseScore + symbolScore + consecutivenumericScore;

	// Ensure the total points do not exceed 9
	points = (points > 9) ? 9 : points;

	// Return the calculated points as the password strength score
	return points;
}


