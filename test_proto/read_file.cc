#include <fstream>
#include <iostream>
#include <string>
#include "zip_code.pb.h"

int main(int argc, char* argv[]) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    demo::ZipCode zip_code;
    {
        // Read the existing address book.
        std::fstream input(argv[1], std::ios::in | std::ios::binary);
        if (!zip_code.ParseFromIstream(&input)) {
            std::cerr << "Failed to parse address book." << std::endl;
            return -1;
        }
    }

    std::cout << zip_code.code() << std::endl;

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
}