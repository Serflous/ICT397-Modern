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
	std::vector<GameObject*>::iterator objIter;
	m_renderer->SetView(m_camera);
	m_renderer->RenderTerrain(m_terrain);
	for (objIter = m_gameObjects.begin(); objIter != m_gameObjects.end(); objIter++)
	{
		m_renderer->RenderGameObject(*objIter);
	}
	m_renderer->RenderSkybox(m_skybox);
	m_renderer->RenderGUI(m_gui);
}

void Scene::UpdateScene(int deltaTime)
{
	std::vector<GameObject*>::iterator objIter;
	std::vector<AABB> boxes;
	for (objIter = m_gameObjects.begin(); objIter != m_gameObjects.end(); objIter++)
	{
		(*objIter)->UpdateBoundingBoxWithPosition();
		boxes.push_back((*objIter)->GetBoundingBox());
	}
	m_camera->Move(boxes, deltaTime);
	float xPos = m_camera->GetPosition().x / m_terrain->GetScale().x;
	float zPos = m_camera->GetPosition().z / m_terrain->GetScale().z;
	float relHeight = m_terrain->GetRelativeHeight(xPos, zPos);
	relHeight = relHeight * ((float)m_terrain->GetScale().y) + (float)m_camera->GetCamViewHeight();
	m_camera->SetHeight(relHeight);
}

void Scene::SetTerrain(Terrain * terrain)
{
	m_terrain = terrain;
}

void Scene::SetSkybox(Skybox * skybox)
{
	m_skybox = skybox;
}

void Scene::SetGUI(GUI * gui)
{
	m_gui = gui;
}