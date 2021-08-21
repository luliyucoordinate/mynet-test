#include <iostream>
#include <gflags/gflags.h>
#include "test.h"

DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german",
                "comma-separated list of languages to offer in the 'lang' menu");

static bool ValidatePort(const char* flagname, int32_t value) {
   if (value > 0 && value < 32768)   // value is ok
     return true;
   printf("Invalid value for --%s: %d\n", flagname, (int)value);
   return false;
}
DEFINE_int32(port, 0, "What port to listen on");
DEFINE_validator(port, &ValidatePort);

int main(int argc, char* argv[]) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << FLAGS_big_menu << " " << FLAGS_languages << std::endl;
    std::cout << port_validator_registered << std::endl;
}