#include "dialoglist.h"

#include <Windows.h>
#include <random>

int fnRandomGenerator(int range)
{
	std::random_device rand_device;
	std::uniform_int_distribution distribution(1, range);
	std::mt19937 engine(rand_device());
	return distribution(engine);
}

void fnSpawnModalMsg()
{
	const int fate = fnRandomGenerator(6);
	if (fate == 6)
		fnInduceBSODHardCrash();
	else
	{
		// random messages while playing
		const int response = MessageBoxW(
			nullptr,
			alpDialog[fate - 1],
			L"Russian Roulette",
			MB_YESNO | MB_ICONWARNING | MB_SYSTEMMODAL);
		if (response == IDYES)
			fnSpawnModalMsg();
	}
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// initial welcome modal
	const int response = MessageBoxW(
		nullptr, 
		lpInitialDescription,
		L"Russian Roulette",
		MB_YESNO | MB_ICONQUESTION | MB_SYSTEMMODAL);

	if (response == IDYES) /* if user agrees to play */
		fnSpawnModalMsg();
}