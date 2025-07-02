#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(Baseball, TryGameTest)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), std::length_error);
}

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}