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
		if (guessNumber == target)
		{
			return { true, 3, 0 };
		}

		if (isTwoStrike(guessNumber) == true)
		{
			return { false, 2, 0 };
		}
		
		int cnt_strike = 0;
		int cnt_ball = 0;
		for (int i = 0; i < 3; i++)
		{
			if (guessNumber[i] == target[i]) cnt_strike++;
			else
			{
				if (guessNumber[i] <= '3') cnt_ball++;
			}
		}
		
		return { false, cnt_strike, cnt_ball };
	}

private:
	bool isTwoStrike(const string& guessNumber)
	{
		int cnt_strike = 0;
		for (int idx = 0; idx < 3; idx++)
		{
			if (guessNumber[idx] == target[idx]) cnt_strike++;
		}

		if (cnt_strike == 2) return true;
		return false;
	}

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

	string target;
};