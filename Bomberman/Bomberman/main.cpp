#include "Manager.h"

int main()
{

	Manager *newManager = new Manager();
	
	

	try
	{
		if (newManager->InitIntro())
			if(newManager->GameLoop())
				newManager->InitEndGameWindow();

				
	}
	catch (const std::exception& ex)
	{
		newManager->ErrorPopOut(ex);
	}

	return 0;
}