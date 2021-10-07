#include "flatbuffers/flatbuffers.h"
#include "multi_root_generated.h"
#include <iostream>
#include <fstream>

using namespace mytest;

int main() {
    flatbuffers::FlatBufferBuilder builder;
    builder.ForceDefaults(true);
    auto one_create = Createone(builder);
    builder.Finish(one_create);

    auto one_c = flatbuffers::GetMutableRoot<one>(builder.GetBufferPointer());
    one_c->mutate_x(1);
    std::cout << one_c->x() << std::endl;

    auto two_create = Createone(builder, 2, 2);
    builder.Finish(two_create);
    auto two_c = flatbuffers::GetRoot<one>(builder.GetBufferPointer());
    std::cout << two_c->x() << std::endl;
}