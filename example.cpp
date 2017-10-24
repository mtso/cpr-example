#include <iostream>

#include <cpr/cpr.h>
#include <json.hpp>

using namespace nlohmann;

int main(int argc, char** argv) {
    auto test = "https://jsonbin.io/b/59eeea97ed25d0573bf19888";

    // auto response = cpr::Get(cpr::Url{"https://httpbin.org/get"});
    // auto json = nlohmann::json::parse(response.text);
    // // std::cout << json.dump(4) << std::endl;

    // std::cout << json["headers"].dump(2) << std::endl;

    auto response = cpr::Get(cpr::Url{test});
    auto d = json::parse(response.text);
    std::cout << d["list"].size() << std::endl;

    auto chars = d["list"];
    for (int i = 0; i < chars.size(); i++) {
        std::cout << chars[i] << std::endl;
    }

    // std::cout << response.text << std::endl;
}
