#include <iostream>
#include <string>
#include <cstdlib>

#include <cpr/cpr.h>
#include <json.hpp>

using namespace nlohmann;

// Populate the branch list
// Fetch commits for each branch
// Flatten commits by unique hash ID
// Hold the commit data in a list structure
int main(int argc, char** argv) {
    auto test = "https://jsonbin.io/b/59eeea97ed25d0573bf19888";
    std::string test3 = "https://jsonbin.io/b/59eeea97ed25d0573bf19888";

    std::string api_url = "https://gitlab.com/api/v4/projects/";
    std::string api_token = std::getenv("GITLAB_TOKEN");
    std::string project_id = std::getenv("GITLAB_PROJECTID");

    // std::string commits_url = api_url + branch_id + "/repository/commits?private_token=" + api_token;
    std::string branches_url = api_url + project_id + "/repository/branches?private_token=" + api_token;

    auto response = cpr::Get(cpr::Url{branches_url});

    auto resp_data = json::parse(response.text);

    for (int i = 0; i < resp_data.size(); i++) {
        std::cout << resp_data[i]["name"] << std::endl;
    }


    // auto response = cpr::Get(cpr::Url{"https://httpbin.org/get"});
    // auto json = nlohmann::json::parse(response.text);
    // // std::cout << json.dump(4) << std::endl;

    // std::cout << json["headers"].dump(2) << std::endl;

    // auto response = cpr::Get(cpr::Url{test3});
    // auto d = json::parse(response.text);
    // std::cout << d["list"].size() << std::endl;

    // auto chars = d["list"];
    // for (int i = 0; i < chars.size(); i++) {
    //     std::cout << chars[i] << std::endl;
    // }

    // std::cout << response.text << std::endl;
}
