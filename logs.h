/*

   nsjail - logging
   -----------------------------------------

   Copyright 2014 Google Inc. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#ifndef NS_LOGS_H
#define NS_LOGS_H

#include <getopt.h>
#include <stdbool.h>

#include <string>

namespace logs {

#define LOG_HELP(...) logs::logMsg(logs::HELP, __FUNCTION__, __LINE__, false, __VA_ARGS__);
#define LOG_HELP_BOLD(...)                                                                         \
	logs::logMsg(logs::HELP_BOLD, __FUNCTION__, __LINE__, false, __VA_ARGS__);

#define LOG_D(...)                                                                                 \
	if (logs::getLogLevel() <= logs::DEBUG) {                                                  \
		logs::logMsg(logs::DEBUG, __FUNCTION__, __LINE__, false, __VA_ARGS__);             \
	}
#define LOG_I(...)                                                                                 \
	if (logs::getLogLevel() <= logs::INFO) {                                                   \
		logs::logMsg(logs::INFO, __FUNCTION__, __LINE__, false, __VA_ARGS__);              \
	}
#define LOG_W(...)                                                                                 \
	if (logs::getLogLevel() <= logs::WARNING) {                                                \
		logs::logMsg(logs::WARNING, __FUNCTION__, __LINE__, false, __VA_ARGS__);           \
	}
#define LOG_E(...)                                                                                 \
	if (logs::getLogLevel() <= logs::ERROR) {                                                  \
		logs::logMsg(logs::ERROR, __FUNCTION__, __LINE__, false, __VA_ARGS__);             \
	}
#define LOG_F(...)                                                                                 \
	if (logs::getLogLevel() <= logs::FATAL) {                                                  \
		logs::logMsg(logs::FATAL, __FUNCTION__, __LINE__, false, __VA_ARGS__);             \
	}
#define LOG_STAT(...)                                                        \
	if (logs::getLogLevel() <= logs::STAT) {                             \
		logs::logMsg(logs::STAT, "__STAT__", 0, false, __VA_ARGS__); \
	}

#define PLOG_D(...)                                                                                \
	if (logs::getLogLevel() <= logs::DEBUG) {                                                  \
		logs::logMsg(logs::DEBUG, __FUNCTION__, __LINE__, true, __VA_ARGS__);              \
	}
#define PLOG_I(...)                                                                                \
	if (logs::getLogLevel() <= logs::INFO) {                                                   \
		logs::logMsg(logs::INFO, __FUNCTION__, __LINE__, true, __VA_ARGS__);               \
	}
#define PLOG_W(...)                                                                                \
	if (logs::getLogLevel() <= logs::WARNING) {                                                \
		logs::logMsg(logs::WARNING, __FUNCTION__, __LINE__, true, __VA_ARGS__);            \
	}
#define PLOG_E(...)                                                                                \
	if (logs::getLogLevel() <= logs::ERROR) {                                                  \
		logs::logMsg(logs::ERROR, __FUNCTION__, __LINE__, true, __VA_ARGS__);              \
	}
#define PLOG_F(...)                                                                                \
	if (logs::getLogLevel() <= logs::FATAL) {                                                  \
		logs::logMsg(logs::FATAL, __FUNCTION__, __LINE__, true, __VA_ARGS__);              \
	}

enum llevel_t {
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	FATAL,
	STAT,
	HELP,
	HELP_BOLD,
};

void logMsg(enum llevel_t ll, const char* fn, int ln, bool perr, const char* fmt, ...)
    __attribute__((format(printf, 5, 6)));
void logStop(int sig);
void setLogLevel(enum llevel_t ll);
enum llevel_t getLogLevel(void);
void logFile(const std::string& log_file, int log_fd);
bool logSet();

}  // namespace logs

#endif /* NS_LOGS_H */
