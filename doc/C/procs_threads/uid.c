#include <stdio.h>
#include <unistd.h>

int main() {
	printf("The REAL UID      ~~~~~~~> UID (%d)\n", getuid());
	printf("The effective UID ~~~~~~~> EUID (%d)\n", geteuid());
}
