/**
 *  config.cpp
 *  The configuration stuff.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <yaml-cpp/yaml.h>

#include "config.h"

using namespace std;

Config::Config(string file) {
	config = YAML::LoadFile(file.c_str());
}

map<string, map<string, string> > Config::emulators() {
	map<string, map<string, string> > emulators;
	YAML::Node emu_vector = config["emulators"];

	for (size_t i = 0; i < emu_vector.size(); ++i) {
		YAML::Node emulator = emu_vector[i];
		map<string, string> tmp_emu;

		// Populate the temp map.
		tmp_emu["name"] = emulator["name"].as<string>();
		tmp_emu["icon"] = emulator["icon"]["filename"].as<string>();
		tmp_emu["x"]    = emulator["icon"]["x"].as<string>();
		tmp_emu["y"]    = emulator["icon"]["y"].as<string>();
		tmp_emu["exec"] = emulator["exec"].as<string>();
		tmp_emu["roms"] = emulator["roms"].as<string>();
		if (emulator["ignore_ext"]) {
			tmp_emu["ignore"] = emulator["ignore_ext"].as<string>();
		}

		// Populate the final map.
		emulators[emulator["id"].as<string>()] = tmp_emu;
	}

	return emulators;
}
