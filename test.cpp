#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

int main (int argc, char *argv[])
{
	std::string filename = "/tmp/test.log";
	std::ofstream outputFile(filename);
	while(1)
	{
		outputFile << "foot" << std::endl;
	        outputFile.flush();	
		sleep(5);
		outputFile << "mile" << std::endl;
		outputFile.flush();
		sleep(5);
	}
}
