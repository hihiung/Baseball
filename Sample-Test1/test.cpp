#include "pch.h"
#include "../Baseball/Baseball.cpp"

TEST(BaseballGame, InvalidArgument) {
	Baseball baseball("123");
	EXPECT_THROW(baseball.guess(""), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1543"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1v3"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("121"), std::invalid_argument);
}

TEST(BaseballGame, PerfectMatch) {
	Baseball baseball("123");
	Result result = baseball.guess("123");

	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST(BaseballGame, MissMatch) {
	Baseball baseball("123");
	Result result = baseball.guess("789");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}