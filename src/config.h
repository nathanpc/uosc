/**
 *  config.h
 *  The configuration stuff.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <map>
#include <vector>
#include <yaml-cpp/yaml.h>

class Config {
	private:
		YAML::Node config;

	public:
		Config(std::string file);

		std::map<std::string, std::map<std::string, std::string> > emulators();
};

#endif
