/// @file
///
/// A base class for all real tests.
///

#pragma once

#include <gtest/gtest.h>

namespace advent::tests {

///
/// A base class for all tests.
///
class TestsBase: public testing::Test {
public:
	TestsBase(){};
};

}
