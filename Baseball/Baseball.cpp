#include <stdexcept>
#include <string>

using namespace std;

struct Result {
	bool solved;
	int strikes;
	int balls;
};

const int STRING_LENGTH = 3;

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	bool isCharExistInString(const string& s, const char c)
	{

		int index = s.find(c);
		if (index == -1) return false;
		return true;
	}

	bool isCharAtGivenPosition(const string& s, const char c, const int pos)
	{
		if (s[pos] == c) return true;
		return false;
	}


	Result guess(string guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, STRING_LENGTH, 0 };
		}

		bool solved = false;
		int strikes = getStrikeCount(guessNumber);
		int balls = getBallCount(guessNumber);
		return { solved , strikes, balls };
	}

private:
	void assertIllegalArgument(string guessNumber) {
		if (guessNumber.length() != STRING_LENGTH) {
			throw std::invalid_argument("자리수 오류");
		}
		if (isIncludeChar(guessNumber)) {
			throw std::invalid_argument("숫자로만 구성되어 있지 않음");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("중복수 금지");
		}
	}

	bool isDuplicatedNumber(string guessNumber) {
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isIncludeChar(const string& guessNumber) {
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	int getStrikeCount(string guessNumber) {
		int result = 0;
		for (int position = 0; position < STRING_LENGTH; position++) {
			if (isCharExistInString(question, guessNumber[position]) == false) continue;
			if (isCharAtGivenPosition(question, guessNumber[position], position) == false) continue;
			result++;
		}
		return result;
	}

	int getBallCount(string guessNumber) {
		int result = 0;
		for (int position = 0; position < STRING_LENGTH; position++) {
			char givenChar = guessNumber[position];
			if (isCharExistInString(question, givenChar) == false) continue;
			if (isCharAtGivenPosition(question, givenChar, position)) continue;
			result++;
		}
		return result;
	}

	string question;
};
