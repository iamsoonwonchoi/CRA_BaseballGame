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
	Baseball(const string& guessNumber) : question(guessNumber) {}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
		{
			return { true, 3, 0 };
		}
		return { false, 0, 0 };
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

	string question;
};