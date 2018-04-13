#include "Scene.h"

Scene::Scene()
{

}

Scene::Scene(const Scene & other)
{

}

Scene::~Scene()
{

}

void Scene::SetCamera(Camera * camera)
{
	m_camera = camera;
}

void Scene::AddModelOBJ(ModelOBJ * model)
{
	m_models.push_back(model);
}

void Scene::SetRenderer(Renderer * renderer)
{
	m_renderer = renderer;
}

void Scene::RenderScene()
{
	m_renderer->PrepareRender();
	m_camera->Move();
	int camHeight = 0;
	int xPos = m_camera->GetPosition().x / m_terrain->GetScale().x;
	int zPos = m_camera->GetPosition().z / m_terrain->GetScale().z;
	//camHeight = m_terrain->GetHeight(m_camera->GetPosition().x, m_camera->GetPosition().z) * (m_terrain->GetScale().y) + m_camera->GetCamViewHeight();
	float relHeight = m_terrain->GetRelativeHeight(m_camera->GetPosition().x / m_terrain->GetScale().x, m_camera->GetPosition().z / m_terrain->GetScale().z);
	relHeight = relHeight * (m_terrain->GetScale().y) + m_camera->GetCamViewHeight();
	camHeight = m_terrain->GetHeight(xPos, zPos);
	camHeight = camHeight * (m_terrain->GetScale().y) + m_camera->GetCamViewHeight();
	m_camera->SetHeight(relHeight);
	m_renderer->SetView(m_camera);
	m_renderer->RenderTerrain(m_terrain);
	std::vector<ModelOBJ*>::iterator modelIter;
	for (modelIter = m_models.begin(); modelIter != m_models.end(); modelIter++)
	{
		m_renderer->RenderModel(*modelIter);
	}
}

void Scene::SetTerrain(Terrain * terrain)
{
	m_terrain = terrain;
}