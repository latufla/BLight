// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ObjectBase.h"
#include "EventHeapTest.h"

class BehaviorTest : public ::testing::Test {
};

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);	
	return RUN_ALL_TESTS();
}


