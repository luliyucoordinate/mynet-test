load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@com_github_google_flatbuffers//:build_defs.bzl", "flatbuffer_cc_library")

cc_binary(
    name = "write_file",
    srcs = ["write_file.cc"],
    deps = [
        "monster_fbs",
        "@com_github_google_flatbuffers//:flatbuffers",
    ],
)

cc_binary(
    name = "read_file",
    srcs = ["read_file.cc"],
    deps = [
        "monster_fbs",
        "@com_github_google_flatbuffers//:flatbuffers",
    ],
)
cc_binary(
    name = "test_multi_root",
    srcs = ["test_multi_root.cc"],
    deps = [
        "multi_root",
        "@com_github_google_flatbuffers//:flatbuffers",
    ],
)


flatbuffer_cc_library(
    name = "monster_fbs",
    srcs = ["monster.fbs"],
)

flatbuffer_cc_library(
    name = "multi_root",
    srcs = ["multi_root.fbs"],
)