#pragma once

#include <string>

struct nsjconf_t;

namespace log2file {

void writeStatToFile(const nsjconf_t* nsjconf, const std::string& key, const std::string& value);
void writeStatToFile(const nsjconf_t* nsjconf, const std::string& key, long long value);

}  // namespace log2file
