#include "collected_data.h"

#include "3rd_party/json.hpp"

using std::string;

using json = nlohmann::json;

namespace template_finder {

string CollectedData::ToCompactJson() const {
    json j;
    for(auto &ct: class_templates) {
        j.push_back({
            {"type", CLASS_TEMPLATE},
            {"beg", {
                {"line", ct.template_start.first},
                {"col", ct.template_start.second},
            }},
            {"end", {
                {"line", ct.param_list_end.first},
                {"col", ct.param_list_end.second},
            }}
        });
    }
    return j.dump();
}

}
