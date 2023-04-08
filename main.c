#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* random_file;
const char* random_file_path = "/dev/random";

char* character_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!%^&*()-=_+{}~[]#;':@,./<>?";

int random_integer() {
	char buffer[sizeof(int)];

	fread(buffer, sizeof(int), 1, random_file);

	return *(int*)buffer;
}

void print_password(size_t length) {
	size_t i, character_set_size;
	int x;
	char c;

	assert(character_set != NULL);
	character_set_size = strlen(character_set);
	assert(character_set_size != 0);

	for (i = 0; i < length; i++) {
		x = random_integer();
		c = character_set[x % character_set_size];

		putchar(c);
	}
}

int startup() {
	random_file = fopen(random_file_path, "r");
	if (!random_file)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void cleanup() {
	fclose(random_file);
}

int main(int argc, char** argv) {
	int res;

	res = startup();
	if (res != EXIT_SUCCESS)
		return res;

	print_password(24);

	cleanup();
	return EXIT_SUCCESS;
}

