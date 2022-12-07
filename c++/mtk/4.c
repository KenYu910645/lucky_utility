#include <stdio.h>

int main() {
	char *str[] = {
	    "MediaTekOnlineTesting",
	    "WelcomeToHere",
	    "Hello",
	    "EverydayGenius",
	    "HopeEverythingGood"};
    // "MediaTekOnlineTesting\0WelcomeToHere\0 ....."

    // printf("%c\n", *(str[0]) ); // 'M'

	char* m = str[4] + 4; // E
	char* n = str[1]; // W
	char* p = *(str+2) + 4; // 'Hello' + 4  = 'o'
    // printf("%s\n", "Hello" + 4 ); // 'o' 

	printf("1. %s\n", *(str+1)); // 1. WelcomeToHere
	printf("2. %s\n", (str[3]+8)); // 'Genius', start from G until it reach '\0'
    // printf("2. %c\n", *(str[3]+8)); // 'G'
	printf("3. %c\n", *m); // 'E'
	printf("4. %c\n", *(n+3)); // 'c'
	printf("5. %c\n", *p + 1); // 'o' + 1 = 'p'
	
    
	// 2. Genius
	// 3. E
	// 4. c
	// 5. p
	return 0;
}