#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (std::exception e)
		{

		}
	}

	Baseball game{ "123" };
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
	assertIllegalArgument(string("12"));
	assertIllegalArgument(string("12s"));
	assertIllegalArgument(string("121"));
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Case_TwoStrike)
{
	GuessResult result = game.guess("523");

	EXPECT_TRUE(result.solved == false);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}