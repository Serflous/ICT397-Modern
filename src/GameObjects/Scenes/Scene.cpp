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
	std::vector<Agent*>::iterator agentIter;
	int i;
	for (agentIter = m_agents.begin(), i = 0; agentIter != m_agents.end(); agentIter++, i++)
	{
		m_renderer->RenderGameObject((*agentIter)->GetGameObject(), i);
	}
	m_renderer->RenderTerrain(m_terrain);
	for (objIter = m_gameObjects.begin(); objIter != m_gameObjects.end(); objIter++)
	{
		m_renderer->RenderGameObject(*objIter);
	}
	m_renderer->RenderSkybox(m_skybox);
	m_renderer->FinalizeFramedRender();
	m_renderer->RenderGUI(m_gui);

}

void Scene::UpdateScene(int deltaTime)
{
	std::vector<GameObject*>::iterator objIter;
	std::vector<AABB> boxes;
	for (objIter = m_gameObjects.begin(); objIter != m_gameObjects.end(); objIter++)
	{
		(*objIter)->SetHeight((m_terrain->GetRelativeHeight(((*objIter)->GetPosition().x / m_terrain->GetScale().x), ((*objIter)->GetPosition().z) / m_terrain->GetScale().z) * m_terrain->GetScale().y) + ((*objIter)->GetModelHeight() / 2));
		(*objIter)->Update(deltaTime);
		(*objIter)->UpdateBoundingBoxWithPosition();
		boxes.push_back((*objIter)->GetBoundingBox());
	}
	std::vector<Agent*>::iterator agentIter;
	for (agentIter = m_agents.begin(); agentIter != m_agents.end(); agentIter++)
	{
		GameObject * object = (*agentIter)->GetGameObject();
		(*agentIter)->SetAgentList(m_agents);
		object->SetHeight((m_terrain->GetRelativeHeight((object->GetPosition().x / m_terrain->GetScale().x), (object->GetPosition().z) / m_terrain->GetScale().z) * m_terrain->GetScale().y) + (object->GetModelHeight() / 2));
		object->Update(deltaTime);
		object->UpdateBoundingBoxWithPosition();
		boxes.push_back(object->GetBoundingBox());
	}
	Dispatcher::GetInstance()->Update(deltaTime);
	float pickedId = m_renderer->GetPickedID();
	m_camera->Move(boxes, deltaTime);
	m_player->SetPosition(m_camera->GetPosition());
	float xPos = m_camera->GetPosition().x / m_terrain->GetScale().x;
	float zPos = m_camera->GetPosition().z / m_terrain->GetScale().z;
	float relHeight = m_terrain->GetRelativeHeight(xPos, zPos);
	relHeight = relHeight * ((float)m_terrain->GetScale().y) + (float)m_camera->GetCamViewHeight();
	m_camera->SetHeight(relHeight);
	for (agentIter = m_agents.begin(); agentIter != m_agents.end(); agentIter++)
	{
		(*agentIter)->Update(deltaTime);
	}
	m_player->Update(deltaTime, pickedId, m_agents);
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

void Scene::SetPlayer(Player * player)
{
	m_player = player;
}

void Scene::AddAgent(Agent * agent)
{
	m_agents.push_back(agent);
}