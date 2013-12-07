// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "ObjectBase.h"

class BehaviorTest : public ::testing::Test {
};

TEST_F(BehaviorTest, CreateObject) 
{
	ObjectBase* obj1 = new ObjectBase(1, "obj1");
	ASSERT_TRUE(obj1->getId() == 1);
	ASSERT_TRUE(obj1->getName() == "obj1");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);	
	return RUN_ALL_TESTS();
}


