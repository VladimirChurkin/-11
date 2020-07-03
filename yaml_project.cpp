#include <stdio.h>
#pragma warning(disable : 4996)
#include <stdlib.h>
#include <string.h>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
char* ReadFile(const char* file)
{
	FILE* fd = fopen(file, "r");
	long h;
	if (fd == NULL) {
		return 0;
	}
	else {
		fseek(fd, 0, SEEK_END);
		h = ftell(fd);
	}
	char* textFile = (char*)malloc(h + 1);
	fseek(fd, 0, SEEK_SET);
	fread(textFile, h, 1, fd);
	textFile[h] = 0;
	fclose(fd);
	return textFile;
}

int main()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	string curtime = asctime(timeinfo);
	cin.get();
	char* way = new char[128];
	YAML::Node config = YAML::LoadFile("config.yaml");
	std::string time = config["time"].as<std::string>();
	cout << time;
	config["time"] = curtime;
	std::ofstream fout("config.yaml");
	fout << config;
	return 0;
}