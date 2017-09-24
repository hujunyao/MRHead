#include "mrlog.h"

int main()
{
	plog::init(plog::debug, "Hello.txt");
	LOGD << "Hello log!"; // short macro
	return 0;
}