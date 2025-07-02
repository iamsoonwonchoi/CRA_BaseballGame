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

	Baseball game;
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase)
{
	assertIllegalArgument(string("12"));
	assertIllegalArgument(string("12s"));
}

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}