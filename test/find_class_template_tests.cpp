#include "gtest/gtest.h"

#include <vector>
#include <utility>

#include "template_finder.h"

using std::vector;
using std::make_pair;

TEST(find_class_template, simple) {
    auto res = FindTemplates("data/simple_class_template.h");
    ASSERT_EQ(res.size(), 1u);
    ASSERT_EQ(res[0].template_start, make_pair(3, 1));
    ASSERT_EQ(res[0].param_list_end, make_pair(10, 1));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
