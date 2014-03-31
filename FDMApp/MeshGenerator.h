#pragma once
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Material>
#include <osg/Vec3>

#include <osg/MatrixTransform>
#include <osg/Texture2D>
#include <osg/PolygonStipple>
#include <osg/TriangleFunctor>
#include <osg/io_utils>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osg/Math>
#include <osgUtil/SmoothingVisitor>
#define N 50
#define NUM_FACES 6
#define HEIGHT 1

const float xMin = -50;
const float xMax = 50;
const float zMin = -50;
const float zMax = 50;
const float y = 0;
struct VertexGroup{
	VertexGroup(int h, int t, int c,int u):_head(h),_tail(t),_cross(c),_up(u){}
	VertexGroup(){_head = 0;_tail=0;_cross=0;_up=0;}
	~VertexGroup(){}
	int _head;
	int _tail;
	int _cross;
	int _up;
};


/*
Creates a mesh geode (i.e. a node with geometrical data)
*/
class MeshGenerator
{
public:
	MeshGenerator(void);
	~MeshGenerator(void);

	void CreateMesh();
	void CreateQuad();
	

	osg::ref_ptr<osg::Geode> GetRoot(){return _geode;}
private:
	osg::ref_ptr<osg::Vec3Array> _vertices;
	osg::ref_ptr<osg::Vec3Array> _normals;
	osg::ref_ptr<osg::Vec4Array> _colors;

	osg::ref_ptr<osg::DrawElementsUInt> _indices;

	osg::ref_ptr<osg::Geometry> _geometry;
	osg::ref_ptr<osg::Geode> _geode;
	VertexGroup _faces[NUM_FACES];
};

