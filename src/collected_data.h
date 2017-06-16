#ifndef __COLLECTED_DATA_H__
#define __COLLECTED_DATA_H__

#include <utility>
#include <vector>
#include <string>

struct ClassTemplateData {
    std::pair<int, int> template_start;
    std::pair<int, int> param_list_end;
};

class CollectedData {
public:
    explicit CollectedData(const std::vector<ClassTemplateData> &ts):
        class_templates(ts)
    {}
    std::string ToCompactJson() const;

    const std::vector<ClassTemplateData> class_templates;
private:
    enum JsonEntryTypes {
        CLASS_TEMPLATE
        // to be continued
    };
};

#endif
