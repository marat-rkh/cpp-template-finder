#include "collected_data.h"

using std::string;

using json = nlohmann::json;

namespace template_finder {

string CollectedData::ToJson(int indent) const {
    json j;
    for(auto &ct: class_templates) {
        j.push_back(ct);
    }
    return indent >= 0 ? j.dump(indent) : j.dump();
}

}
