#include <stdio.h>

#include "logger.h"

int main(int argc, char** argv) {
	init_logger(argv);
	LOG(INFO) << "Hello, World";
	return 0;
}