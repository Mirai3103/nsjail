#include "log2file.h"
#include "logs.h"  // LOG_W
#include "config.h" // nsjconf_t

#include <fstream>

namespace log2file {

void writeStatToFile(const nsjconf_t* nsjconf, const std::string& key, const std::string& value) {
	if (nsjconf->stats_file.empty()) return;

	std::ofstream ofs(nsjconf->stats_file, std::ios::app);
	if (!ofs) {
		LOG_W("Cannot open stats file: %s", nsjconf->stats_file.c_str());
		return;
	}
	ofs <<  key << "=" << value << "\n";
}

void writeStatToFile(const nsjconf_t* nsjconf,  const std::string& key, long long value) {
	writeStatToFile(nsjconf, key, std::to_string(value));
}

}  // namespace log2file
