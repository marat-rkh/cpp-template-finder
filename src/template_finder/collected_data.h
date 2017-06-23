#ifndef __COLLECTED_DATA_H__
#define __COLLECTED_DATA_H__

#include <utility>
#include <vector>
#include <string>

#include "3rd_party/json.hpp"

namespace template_finder {

class CollectedData {
public:
    explicit CollectedData(const std::vector<nlohmann::json> &ts):
        class_templates(ts)
    {}
    std::string ToCompactJson() const { return ToJson(-1); }
    std::string ToPrettyJson() const { return ToJson(4); }

    const std::vector<nlohmann::json> class_templates;
private:
    std::string ToJson(int indent) const;
};

}

#endif
