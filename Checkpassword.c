#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"PASSWORD.c" // This User defined header contains the check_password function

int main(int argc, char* argv[]) {
	char* pass;
	/*
	* The Speciel thing is in this password mechanism that does not echo the password you type on screen
	* One of the Linux based environment, passwords are being typed without being displayed (aka echoed) in the terminal
	*/
	pass = getpass("Enter a Password: ");

	// Print the length of the entered password
	printf("password Length: %ld\n", strlen(pass));

	// Print the entered password
	printf("Password: %s\n", pass);

	// Check and print LengthScore
	if (strlen(pass) >= 8) {
		printf("LengthScore: 2\t");
	}
	// Check and print UppercaseScore
	for (int i = 0; i < strlen(pass);i++) {
		if (isupper(pass[i])) {
			printf("UppercaseScore = 2\t");
			break;
		}
	}
	// Check and print LowercaseScore
	for (int i = 0; i < strlen(pass);i++) {
		if (islower(pass[i])) {
			printf("LowercaseScore = 2\t");
			break;
		}
	}
	// Check and print SymbolScore
	for (int i = 0; i < strlen(pass);i++) {
		if (ispunct(pass[i])) {
			printf("SymbolScore = 2\t\t");
			break;
		}
	}
	// Check and print ConsecutiveNumericScore
	int strength = check_password(pass);
	if (strength < 9) {
		printf("ConsecutiveNumericScore = 0\n");
	}
	else {
		printf("ConsecutiveNumericScore = 1\n");
	}

	// Print the overall Password Strength score
	printf("Password Strength: %d\n\n", strength);

	// Provide feedback based on the Password Strength score
	switch (strength) {
	case 9:
		printf("Strongest password!\n\n");
		break;
	case 8:
	case 7:
		printf("Strong password.\n\n");
		break;
	case 6:
	case 5:
		printf("Medium strength password.\n\n");
		break;
	case 4:
	case 3:
		printf("Weak password.\n\n");
		break;
	case 2:
	case 1:
		printf("Weakest password.\n\n");
		break;
	case 0:
		printf("Password is too short.\n\n");
		break;
	default:
		printf("Invalid rank.\n\n");
	}
	// Additional information about password score
	printf("Password full score is 9\nNOTE: Password Stregnth 8 is Enough!, If you want more SECURITY Go Ahead\n");
	return 0;
}
