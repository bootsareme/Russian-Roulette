#pragma once

int fnRandomGenerator(int range);
void fnInduceBSODHardCrash();

inline const wchar_t* lpInitialDescription = L"Russian Roulette is a probabilistic game where you shoot yourself"
	" with a revolver hoping that a bullet does not come out. Likewise, there is a 1 in 6 chance that your computer"
	" will die a horrible death if you play this game. So the question is: will you take the chance and play?";

constexpr const wchar_t* alpDialog[5] = {
	L"Phew! That was a close one. You survived another blank round, do you want to pull the trigger again?",
	L"WOW! You were pretty lucky, try the lottery sometime. Do you want to fire again?",
	L"Hold up. Is there even a bullet in there? Want to test your chances and pull the trigger again?",
	L"Sheesh! Your luck will expire someday, do not pride yourself too much. Want to try again?",
	L"Luck was on your side with that blank round. May luck continue to be on your side. Want to fire again?"
};
