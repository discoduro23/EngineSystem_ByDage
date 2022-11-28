#include <GameManager.h>


void GameManager::init()
{
	EngineManager::CreateSingleton();
	EngineManager::GetInstance().Init();
}

void GameManager::Update()
{
	EngineManager::GetInstance().PreUpdate();
	EngineManager::GetInstance().Update();
	EngineManager::GetInstance().PostUpdate();
}

void GameManager::AddObject(Object* object)
{
	m_objects.push_back(object);
}

void GameManager::RemoveObject(Object* object)
{
	for (int i = 0; i < m_objects.size(); i++) {
		if (m_objects[i] == object) {
			m_objects.erase(m_objects.begin() + i);
		}
	}
}

void GameManager::Destroy()
{
	EngineManager::GetInstance().Destroy();
	EngineManager::GetInstance().Close();
	EngineManager::GetInstance().DestroySingleton();
}


