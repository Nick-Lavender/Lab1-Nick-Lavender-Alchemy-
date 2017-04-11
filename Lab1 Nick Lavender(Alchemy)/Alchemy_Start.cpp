#include "ConInfoStruct.h"
#include "Context.h"
#include "Alchemy.h"

using namespace ConsoleApplicationLayer;

int main()
{
	ConInfoStruct infostruct;
	ConsoleContext &context = ConsoleContext(infostruct);

	Alchemy alchemy(context);
	while (alchemy.Draw());

	return 0;
}