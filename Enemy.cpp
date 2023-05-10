#include "Enemy.hpp"
#include "Game.hpp"

// Move enemy left or right depending on the direction
void Enemy::move_lr() {
// If moving right
    if (m_dir) {
        move(m_speed, 0);
        // Check if the enemy is at the right boundary for regular enemies
        if (x + w >= SPAWN_AREA_END && m_speed != 2) {
            m_dir = !m_dir;
            m_shape.scale(-1, 1);
            setOrigin(w, 0);
        }
            // Check if the enemy is at the right boundary for plane enemies
        else if ((x + w >= SPAWN_AREA_END + PLANE_OFFSET) && m_speed == 2) {
            m_dir = !m_dir;
            m_shape.scale(-1, 1);
            setOrigin(w, 0);
        }
    }
// If moving left
    else {
        move(-m_speed, 0);
        // Check if the enemy is at the left boundary for regular enemies
        if (x <= SPAWN_AREA_BEGIN && m_speed != 2) {
            m_dir = !m_dir;
            m_shape.scale(-1, 1);
            setOrigin(0, 0);
        }
            // Check if the enemy is at the left boundary for plane enemies
        else if ((x + w <= SPAWN_AREA_BEGIN - PLANE_OFFSET) && m_speed == 2) {
            m_dir = !m_dir;
            m_shape.scale(-1, 1);
            setOrigin(0, 0);
        }
    }
}


