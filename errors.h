#define EXTRA_TEXT(check) \
	if(check) { \
		printf("Extraneous text after end of command\n"); \
		continue; \
	}

#define MISSING_PARAM(check) \
	if(!check) { \
		printf("Missing argument\n"); \
		continue; \
	}

#define MISSING_COMMA(check) \
	if(check != ',') { \
		printf("Missing comma\n"); \
		continue; \
	}

#define CONSECUTIVE_COMMA(check) \
	if(check == ',') { \
		printf("Multiple consecutive commas\n"); \
		continue; \
	}

#define NO_NUMBERS(check) \
	if(!check) { \
		printf("No numbers entered\n"); \
		continue; \
	}
