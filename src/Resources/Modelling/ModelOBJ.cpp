#include "ModelOBJ.h"

ModelOBJ::ModelOBJ()
{
	m_vaoId = 0;
	m_vertexCount = 0;
	m_texture = nullptr;
}

ModelOBJ::ModelOBJ(int vaoId, int vertexCount)
{
	m_vaoId = vaoId;
	m_vertexCount = vertexCount;
	m_texture = nullptr;
}

ModelOBJ::ModelOBJ(const ModelOBJ & other)
{
	m_vaoId = other.m_vaoId;
	m_vertexCount = other.m_vertexCount;
}

ModelOBJ::~ModelOBJ()
{

}