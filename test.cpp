#include <iostream>
#include <unistd.h>

int main (int argc, char *argv[])
{
	while(1)
	{
		std::cout << "foot" << std::endl;
		sleep(5);
		std::cout << "mile" << std::endl;
		sleep(5);
	}
}
