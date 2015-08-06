//ObjLoader.h
////////////////////////////////////////////////////////////
#include "Application.h"
#include "Object.h"


#pragma once

typedef std::vector <glm::vec3> stdVec3;
typedef std::vector <glm::vec2> stdVec2;


class ObjLoader: public Object {
public:
	ObjLoader();
	~ObjLoader();
	void buildMesh();
private:

	bool loadOBJ(const char * path,	stdVec3 & out_vertices, stdVec2 & out_uvs, stdVec3 & out_normals);
};

