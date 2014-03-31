#include "MeshGenerator.h"


MeshGenerator::MeshGenerator(void)
{
   _geode = new osg::Geode();
   _geometry = new osg::Geometry();

   //declare the array of vertices. Each vertex is a coordinate (x,y,z)
   _vertices = new osg::Vec3Array;
   _normals = new osg::Vec3Array;
   _colors = new osg::Vec4Array;

    _colors->push_back( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) );
	_colors->push_back( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) );
	_colors->push_back( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) );
	_colors->push_back( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) );

	_indices = new osg::DrawElementsUInt(GL_TRIANGLES,36*HEIGHT);
	_geode->addDrawable(_geometry.get());

	// walls
	_faces[0] = VertexGroup(0,1,3,2); 
	_faces[1] = VertexGroup(1,5,7,3); 
	_faces[2] = VertexGroup(5,4,6,7); 
	_faces[3] = VertexGroup(4,0,2,6); 
	// levels
	_faces[4] = VertexGroup(3,7,6,2);
	_faces[5] = VertexGroup(0,4,5,1);
}


MeshGenerator::~MeshGenerator(void)
{
	
}
void MeshGenerator::CreateMesh()
{
	osg::Vec4 ColorSet[4] = {osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f),osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f),osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f),osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f)};

   for(int i=0;i<N;i++)
   {
	   float z = zMin + (float)(i)/(float)(N-1)*(zMax-zMin);
	   for(int j=0;j<N;j++)
	   {
		   float x = xMin + (float)(j)/(float)(N-1)*(xMax - xMin);
		   _vertices->push_back( osg::Vec3(x,y,z) );
		   _normals->push_back(osg::Vec3(0.0f,1.0f,0.0f));
		   _colors->push_back(ColorSet[4%(i+1)]);
	   }
   }
}
void MeshGenerator::CreateQuad()
{
	osg::Vec4 ColorSet[4] = {osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f),osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f),osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f),osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f)};


	int M = HEIGHT+1;
	float scale = 0.25;
	for(int l=0;l<M;l++)
	{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			_vertices->push_back(osg::Vec3(scale*(float)j,scale*(float)l,scale*(float)i) );
			//_colors->push_back(ColorSet[4%(l+1)]);
			_colors->push_back(ColorSet[3]);
		}
	}
	}

	int k=0;
	

	for(int i=0;i<HEIGHT;i++)
	{
		for(int j=0;j<NUM_FACES;j++)
		{
			int v1 = _faces[j]._head;
			int v2 = _faces[j]._tail;
			int v3 = _faces[j]._cross;
			int v4 = _faces[j]._up;

			(*_indices)[k++] = v1;
			(*_indices)[k++] = v2;
			(*_indices)[k++] = v3;

			(*_indices)[k++] = v4;
			(*_indices)[k++] = v1;
			(*_indices)[k++] = v3;

		}
	
	}
	_geometry->setVertexArray(_vertices.get());
	_geometry->addPrimitiveSet(_indices.get());
	_geometry->setColorArray(_colors.get());
	osgUtil::SmoothingVisitor::smooth(*_geometry);
	_geometry->setColorBinding( osg::Geometry::BIND_PER_VERTEX );
	/*
	_normals->push_back( osg::Vec3(0.0f,-1.0f, 0.0f) );

   _geometry->setVertexArray(_vertices.get());
   _geometry->setColorArray(_colors.get());
   _geometry->setNormalArray(_normals.get());
   _geometry->setNormalBinding( osg::Geometry::BIND_OVERALL );
   _geometry->setColorBinding( osg::Geometry::BIND_PER_VERTEX );
   _geometry->addPrimitiveSet(new osg::DrawArrays(GL_QUADS,0,4));
   */
}
