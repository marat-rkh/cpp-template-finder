#ifndef __JSON_FORMAT_H__
#define __JSON_FORMAT_H__ value

namespace template_finder {

struct TemplateKind {
    enum {
        CLASS_TEMPLATE = 0
    };
};

struct TemplateParameterKind {
    enum {
        TYPE = 0,
        NON_TYPE = 1,
        TEMPLATE = 2
    };
};

}

#endif
