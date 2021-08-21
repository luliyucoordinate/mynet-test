load("@rules_cc//cc:defs.bzl", "cc_proto_library", "cc_binary")
load("@rules_proto//proto:defs.bzl", "proto_library")

cc_proto_library(
    name = "zip_code_cc_proto",
    deps = [":zip_code_proto"],
)

proto_library(
    name = "zip_code_proto",
    srcs = ["zip_code.proto"],
)

cc_proto_library(
    name = "zip_code2_cc_proto",
    deps = [
        ":zip_code2_proto"
    ],
)

proto_library(
    name = "zip_code2_proto",
    srcs = [
        "zip_code2.proto",
        "zip_code.proto"    
    ],
)

cc_binary(
    name = "write_file",
    srcs = ["write_file.cc"],
    deps = [":zip_code_cc_proto"],
)

cc_binary(
    name = "read_file",
    srcs = ["read_file.cc"],
    deps = [":zip_code_cc_proto"],
)