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

void Scene::AddGameObject(GameObject * model)
{
	m_gameObjects.push_back(model);
}

void Scene::SetRenderer(Renderer * renderer)
{
	m_renderer = renderer;
}

void Scene::RenderScene()
{
	m_renderer->PrepareRender();
	m_camera->Move();
	//int camHeight = 0;
	int xPos = m_camera->GetPosition().x / m_terrain->GetScale().x;
	int zPos = m_camera->GetPosition().z / m_terrain->GetScale().z;
	//camHeight = m_terrain->GetHeight(m_camera->GetPosition().x, m_camera->GetPosition().z) * (m_terrain->GetScale().y) + m_camera->GetCamViewHeight();
	float relHeight = m_terrain->GetRelativeHeight(xPos, zPos);
	relHeight = relHeight * ((float)m_terrain->GetScale().y) + (float)m_camera->GetCamViewHeight();
	//camHeight = m_terrain->GetHeight(xPos, zPos);
	//camHeight = camHeight * (m_terrain->GetScale().y) + m_camera->GetCamViewHeight();
	m_camera->SetHeight(relHeight);
	m_renderer->SetView(m_camera);
	m_renderer->RenderTerrain(m_terrain);
	std::vector<GameObject*>::iterator objIter;
	for (objIter = m_gameObjects.begin(); objIter != m_gameObjects.end(); objIter++)
	{
		m_renderer->RenderGameObject(*objIter);
	}
}

void Scene::SetTerrain(Terrain * terrain)
{
	m_terrain = terrain;
}