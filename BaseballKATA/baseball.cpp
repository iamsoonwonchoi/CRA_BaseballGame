#include <string>
#include <stdexcept>

using std::string;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(const string& answer) : target(answer) {}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		
		int valid_num_count = getOneTwoThreeCount(guessNumber);
		int strike_count = getStrikeCount(guessNumber);
		int ball_count = valid_num_count - strike_count;

		if (strike_count == MAX_LENGTH) return { true,MAX_LENGTH,0 };
		return { false, strike_count,ball_count };
	}

private:
	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw std::length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			throw std::invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber))
		{
			throw std::invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicatedNumber(const string& guessNumber)
	{
		if ((guessNumber[0] == guessNumber[1])
			|| (guessNumber[0] == guessNumber[2])
			|| (guessNumber[1] == guessNumber[2]))
		{
			return true;
		}
		return false;
	}

	int getOneTwoThreeCount(const string& guessNumber)
	{
		int result = 0;
		for (char num : guessNumber)
		{
			if (num >= '0' && num <= '3') result++;
		}
		return result;
	}

	int getStrikeCount(const string& guessNumber)
	{
		int result = 0;
		for (int idx = 0; idx < MAX_LENGTH; idx++)
		{
			if (guessNumber[idx] == target[idx]) result++;
		}
		return result;
	}

	static const int MAX_LENGTH = 3;
	string target;
};