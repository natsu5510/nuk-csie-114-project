#include <iostream>
using namespace std;

int main()
{
	int LocateX = 0, LocateY = 0;
	int RotX = 0, RotY = 0;
	int ScentX[100] = { 0 }, ScentY[100] = { 0 },J=0,U = 0;
	char Vec;
	char ScentVec[100] = { 'C' };
	string WayCommand;

	cin >> LocateX >> LocateY;
	while (cin >> RotX >> RotY >> Vec >> WayCommand)
	{
		int IfLost = 0;
		for (int i = 0; i < WayCommand.size(); i++)
		{
			//turn right
			if (WayCommand[i] == 'R')
			{
				if (Vec == 'N')
				{
					Vec = 'E';
				}
				else if (Vec == 'E')
				{
					Vec = 'S';
				}
				else if (Vec == 'S')
				{
					Vec = 'W';
				}
				else if (Vec == 'W')
				{
					Vec = 'N';
				}
			}
			//turn left
			else if (WayCommand[i] == 'L')
			{
				if (Vec == 'N')
				{
					Vec = 'W';
				}
				else if (Vec == 'E')
				{
					Vec = 'N';
				}
				else if (Vec == 'S')
				{
					Vec = 'E';
				}
				else if (Vec == 'W')
				{
					Vec = 'S';
				}
			}
			//forward
			else if (WayCommand[i] == 'F')
			{
				for (int p = 0;p <=J;p++)
				{
					if (RotX == ScentX[p] && RotY == ScentY[p] && Vec == ScentVec[p])
					{
						p = J + 1;
						U = U + 1;
						break;
					}
				}
				if (U != 0)
				{
					U = U - 1;
				}
				else if (Vec == 'N')
				{
					RotY+=1;
					if (RotY > LocateY || RotY < 0)
					{
						IfLost = 1;
						RotY -= 1;
						break;
					}
				}
				else if (Vec == 'E')
				{
					RotX+=1;
					if (RotX > LocateX || RotX < 0)
					{
						IfLost = 1;
						RotX -= 1;
						break;
					}
				}
				else if (Vec == 'S')
				{
					RotY-=1;
					if (RotY > LocateY || RotY < 0)
					{
						IfLost = 1;
						RotY += 1;
						break;
					}
				}
				else if (Vec == 'W')
				{
					RotX-=1;
					if (RotX > LocateX || RotX < 0)
					{
						IfLost = 1;
						RotX += 1;
						break;
					}
				}
				
			}

		}
		//output
		if (IfLost == 0)
		{
			cout << RotX<<" " << RotY<<" " << Vec << endl;
		}
		else
		{
			cout << RotX << " " << RotY << " " << Vec << " " << "Lost" << endl;
			ScentX[J] = RotX;
			ScentY[J] = RotY;
			ScentVec[J] = Vec;
			J = J + 1;
		}
	}

}
