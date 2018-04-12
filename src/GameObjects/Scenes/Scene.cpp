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
	m_renderer->StartShader();
	m_renderer->PrepareRender();
	m_camera->Move();
	m_renderer->SetView(m_camera);
	m_renderer->RenderTerrain(m_terrain);
	std::vector<ModelOBJ*>::iterator modelIter;
	for (modelIter = m_models.begin(); modelIter != m_models.end(); modelIter++)
	{
		m_renderer->RenderModel(*modelIter);
	}
	m_renderer->StopShader();
}

void Scene::SetTerrain(Terrain * terrain)
{
	m_terrain = terrain;
}