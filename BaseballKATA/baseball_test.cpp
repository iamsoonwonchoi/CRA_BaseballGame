#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(Baseball, TryGameTest)
{
	EXPECT_EQ(1, 1);
}

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}