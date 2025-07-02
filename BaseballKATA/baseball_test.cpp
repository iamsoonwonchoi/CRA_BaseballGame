#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test
{
public:
	void assertIllegalArgument(const string& guessNumber)
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

	void checkGuess(const string& guessNumber, bool expected_solved, int expected_strike, int expected_ball)
	{
		GuessResult result = game.guess(guessNumber);

		EXPECT_TRUE(expected_solved == result.solved);
		EXPECT_EQ(expected_strike, result.strikes);
		EXPECT_EQ(expected_ball, result.balls);
	}

private:
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
	checkGuess("123", true, 3, 0);
}

TEST_F(BaseballFixture, Case_TwoStrike)
{
	checkGuess("523", false, 2, 0);
	checkGuess("129", false, 2, 0);
	checkGuess("173", false, 2, 0);
}

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}