#pragma once

#include "../../../spritesheet.h"

namespace Impacto {
namespace Profile {
namespace SG0 {
namespace ClearListMenu {

int constexpr EndingCount = 6;

void Configure();

inline Sprite BackgroundSprite;
// Per tube: lit sprite, position, ending title and clear flag.
inline Sprite TubeSprites[EndingCount];
inline glm::vec2 TubePositions[EndingCount];
inline Sprite LabelSprites[EndingCount];
inline glm::vec2 LabelPositions[EndingCount];
inline int EndingFlags[EndingCount];
inline Sprite GuideSprite;
inline glm::vec2 GuidePos;
inline int CountMax;

}  // namespace ClearListMenu
}  // namespace SG0
}  // namespace Profile
}  // namespace Impacto
