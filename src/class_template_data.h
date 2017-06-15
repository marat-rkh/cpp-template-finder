#ifndef __CLASS_TEMPLATE_DATA_H_
#define __CLASS_TEMPLATE_DATA_H_

#include <utility>

struct ClassTemplateData {
    std::pair<int, int> template_start;
    std::pair<int, int> param_list_end;
};

#endif
