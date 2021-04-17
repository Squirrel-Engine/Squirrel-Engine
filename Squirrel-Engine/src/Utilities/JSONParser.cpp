#include "JSONParser.h"
using json = nlohmann::json;

JSONParser::JSONParser(std::string path) {
    parsePath = path;
}
nlohmann::json JSONParser::parseFile_json() {
    std::ifstream i(parsePath);
    json j;
    j << i;
    return j;
}
std::map<std::string, std::string> JSONParser::parseFile_map(){
    std::ifstream i(parsePath);
    json j;
    j << i;
    std::map<std::string, std::string> configMap = j;
    for (const auto& x : configMap) {
        std::cout << x.first << ": " << x.second << "\n";
    }
    return configMap;
}
