#include "SFML/Graphics.hpp"
#include "BaseTower.h"
#include "BaseEnemy.h"
#include "PlayerStronghold.h"
#include <memory>
/////////////////////////////////////////////////////////
/// \brief A tower super class for others to inherit from
///
///	Contributors:  Matthew Watson, Kevin Boylan, Dermot Mac Conville
////////////////////////////////////////////////////////////
class WavePhase
{
public:
	WavePhase();
	WavePhase(std::shared_ptr<int> mapCount);
	void Draw(sf::RenderWindow *window, sf::Shader *shader, std::shared_ptr<std::vector<BaseTower>> towers);
	void Update(std::shared_ptr<std::vector<BaseTower>> towers, std::shared_ptr<int> currency, std::shared_ptr<int> score, bool *pGameOver);
	void TowerTargeting(std::shared_ptr<std::vector<BaseTower>> towers);
	int getWaveState();
	int waveState;
	int getTowerHealth();
private:
	std::vector<BaseEnemy> m_enemies;
	std::shared_ptr<sf::Texture> slowEnemyTexture;
	std::shared_ptr<sf::Texture> fastEnemyTexture;
	std::shared_ptr<sf::Texture> mediumEnemyTexture;
	sf::Texture baseTexture;
	PlayerStronghold m_base;
	void WavePhase::CheckBaseCollision();

	int enemyCount;
	void Waves();
	int spawnTimer;
	bool comparePercentageHealth(int currentHealthOne, int maxHealthOne, int currentHealthTwo, int maxHealthTwo);
	std::shared_ptr<int> m_map;
	void EnemySpawns();

	int wave;
};