#include "GridPositions.h"


GridPositions::GridPositions(void)
{
	_N = 100;
}


GridPositions::~GridPositions(void)
{
}
void GridPositions::GenerateGrid()
{
	int yDiff = yMax - yMin;
	int xDiff = xMax - xMin;
	int zDiff = zMax - zMin;

	int numVertices = _N*_N*_N;
	int numFaces = (_N-1)*(_N-1)*(_N-1);
	std::ofstream pointsFile("points.ply");

	for(int k=0;k<_N;k++)
	{
		float y = yBound + (float)(k)/(float)(_N-1)*(yDiff);

		for(int i=0;i<_N;i++)
		{
		  float z = zMin + (float)(i)/(float)(_N-1)*(zDiff);
		  for(int j=0;j<_N;j++)
		  {
		   float x = xMin + (float)(j)/(float)(_N-1)*(xDiff);
		   pointsFile << "v " << x << std::setw(5) << y << std::setw(5) << z;
		   if(j!=_N-1)
			   pointsFile << std::endl;
		//   meshVertices->push_back( osg::Vec3(x,y,z) );
		//   meshVertexNormals->push_back(osg::Vec3(0,1,0));
	      }
	    }
	}
	for(int k=0;k<_N;k++)
	{
		for(int i=0;i<_N;i++)
		{
			for(int j=0;j<_N;i++)
			{
				pointsFile << "vn" << std::setw(5) << 0 << std::setw(5) << 0 << std::setw(5) << 1;
				if(j!=_N-1)
					pointsFile << std::endl;
			}
		}
	}

	for(int k=0;k<_N-1;k++)
   {
	for(int i=0;i<_N-1;i++)
	{
	   for(int j=0;j<_N-1;j++)
	   {
		   int v1 = i*_N+j;
		   int v2 = i*_N+j+1;
		   int v3 = (i+1)*_N+j+1;
		   int v4 = (i+1)*_N+j;
			pointsFile << "f " << v1 << " " << v2 << " " << v3 << " " << v4 << std::endl;
	   }
	}
	}

	pointsFile.close();
}