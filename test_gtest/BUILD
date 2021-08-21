load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
  name = "main",
  size = "small",
  srcs = ["main.cc", "main.h", "main_test.cc"],
  deps = ["@com_google_googletest//:gtest_main"],
)