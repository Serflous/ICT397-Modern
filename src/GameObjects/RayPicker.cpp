#include "RayPicker.h"

RayPicker::RayPicker(glm::mat4x4 projectionMatrix)
{
	m_projectionMatrix = projectionMatrix;
}

RayPicker::RayPicker(const RayPicker & other)
{
	m_projectionMatrix = other.m_projectionMatrix;
	m_ray = other.m_ray;
	m_camera = other.m_camera;
}

RayPicker::~RayPicker()
{

}

glm::vec3 RayPicker::GetRay()
{
	return m_ray;
}

void RayPicker::Update(Camera * camera)
{
	m_camera = camera;
	glm::mat4x4 viewMatrix = MathHelper::CreateViewMatrix(m_camera);
	int x = 0, y = 0;
	int winX = 0, winY = 0;
	float normedX = 0, normedY = 0;
	InputManager::GetInstance()->GetMousePosition(x, y);
	GlutWindow::GetInstance()->GetWindowSize(winX, winY);
	normedX = (2 * x) / (float)(winX - 1);
	normedY = -((2 * y) / (float)(winY - 1));
	glm::vec4 clipSpace(normedX, normedY, -1.0f, 1.0f);
	glm::mat4x4 projectionMatrixInv = glm::inverse(m_projectionMatrix);
	glm::vec4 eyeSpaceCalc = projectionMatrixInv * clipSpace;
	glm::vec4 eyeSpace(eyeSpaceCalc.x, eyeSpaceCalc.y, -1.0f, 0.0f);
	glm::mat4x4 viewMatrixInv = glm::inverse(viewMatrix);
	glm::vec4 worldSpace = viewMatrixInv * eyeSpace;
	glm::vec3 ray(worldSpace.x, worldSpace.y, worldSpace.z);
	m_ray = glm::normalize(ray);
}