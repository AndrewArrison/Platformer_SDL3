#always reoslve x fist
	FrameMoveX += veloX;
	then check if it will collide
	if coolied move back
then y
Got it! Here's the original code exactly as it appeared in the text, copied without any content changes or formatting modifications:

cpp
Copy
Edit
std::vector<SDL_Rect> TileMap::getRects(float Px, float Py) {
    std::vector<SDL_Rect> collisions;
    int leftTile = std::floor(Px / 32);
    int rightTile = leftTile + 1;
    int topTile = std::floor(Py / 32);
    int bottomTile = topTile + 1;
    for (int y = topTile; y <= bottomTile; y++) {
        for (int x = leftTile; x <= rightTile; x++) {
            if (tilemap[x][y] == 1) {
                SDL_Rect tileRect = { x * 32, y * 32, 32, 32 };
                SDL_Rect playerRect = { (int)Px, (int)Py, 32, 32 };
                SDL_Rect result;
                if (SDL_IntersectRect(&tileRect, &playerRect, &result)) {
                    collisions.push_back(tileRect);
                }
            }
        }
    }
    return collisions;
}
cpp
Copy
Edit
void Player::update() {
    handleInput();
    m_velocityY += m_accelerationY;
    m_velocityY = std::min(10.0f, m_velocityY);
    float newPlayerX = m_x + m_velocityX;
    float newPlayerY = m_y + m_velocityY;
    SDL_Rect playerRect = { (int)newPlayerX, (int)newPlayerY, 32, 32 };
    std::vector<SDL_Rect> collisions = m_tilemap->getRects(newPlayerX, newPlayerY);
    for (SDL_Rect tile : collisions) {
        SDL_Rect result;
        if (SDL_IntersectRect(&playerRect, &tile, &result)) {
            // Resolve Y axis first (vertical)
            if (result.w < result.h) {
                // Horizontal collision
                if (newPlayerX > tile.x) {
                    newPlayerX += result.w;
                } else {
                    newPlayerX -= result.w;
                }
                m_velocityX = 0;
            } else {
                // Vertical collision
                if (newPlayerY > tile.y) {
                    newPlayerY += result.h;
                } else {
                    newPlayerY -= result.h;
                    m_onGround = true;
                }
                m_velocityY = 0;
            }
            // Update player rect after resolution
            playerRect.x = (int)newPlayerX;
            playerRect.y = (int)newPlayerY;
        }
    }
    m_x = newPlayerX;
    m_y = newPlayerY;
}
cpp
Copy
Edit
void Player::update()
{
    handleInput();

    // Apply gravity
    m_velocityY += m_accelerationY;
    m_velocityY = std::min(m_velocityY, 10.0f); // terminal velocity

    // Move horizontally
    float newX = m_x + m_velocityX;
    SDL_Rect horizontalRect = { (int)newX, (int)m_y, 32, 32 };
    auto collisionsX = m_tilemap->getRects(newX, m_y);

    for (const auto& tile : collisionsX) {
        SDL_Rect intersection;
        if (SDL_IntersectRect(&horizontalRect, &tile, &intersection)) {
            if (m_velocityX > 0) {
                newX = tile.x - 32;
            } else if (m_velocityX < 0) {
                newX = tile.x + tile.w;
            }
            m_velocityX = 0;
        }
    }

    m_x = newX;

    // Move vertically
    float newY = m_y + m_velocityY;
    SDL_Rect verticalRect = { (int)m_x, (int)newY, 32, 32 };
    auto collisionsY = m_tilemap->getRects(m_x, newY);

    m_onGround = false;

    for (const auto& tile : collisionsY) {
        SDL_Rect intersection;
        if (SDL_IntersectRect(&verticalRect, &tile, &intersection)) {
            if (m_velocityY > 0) {
                newY = tile.y - 32;
                m_onGround = true;
            } else if (m_velocityY < 0) {
                newY = tile.y + tile.h;
            }
            m_velocityY = 0;
        }
    }

    m_y = newY;
}
Let me know if you’d like these saved into .cpp files or organized in any specific way.











Tools


