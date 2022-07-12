#include "logger.h"

#include "glog/logging.h"

void init_logger(char* argv[]) {
	FLAGS_alsologtostderr = 1;
	google::InitGoogleLogging(argv[0]);
}