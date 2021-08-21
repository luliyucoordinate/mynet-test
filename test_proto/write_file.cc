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
        if (!input) {
            std::cout << argv[1] << ": File not found.  Creating a new file." << std::endl;
        } else if (!zip_code.ParseFromIstream(&input)) {
            std::cerr << "Failed to parse address book." << std::endl;
            return -1;
        }
    }
    zip_code.set_code("hello proto");
    {
        // Write the new address book back to disk.
        std::fstream output(argv[1], std::ios::out | std::ios::trunc | std::ios::binary);
        if (!zip_code.SerializeToOstream(&output)) {
            std::cerr << "Failed to write address book." << std::endl;
            return -1;
        }
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
}