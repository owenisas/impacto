#pragma once

#include <vector>

#include "../../../spritesheet.h"
#include "../../ui/systemmenu.h"

namespace Impacto {
namespace Profile {
namespace SG0 {
namespace SystemMenu {

void Configure();

inline Sprite BackgroundSprite;  // monitor frame
inline RectF MonitorScreen;      // where the screen capture goes
inline Sprite GlassSprite;
inline float GlassOpacity;
inline Sprite RingSprite;
inline glm::vec2 RingPos;

// Indexed by the script's jump-table id.
inline glm::vec2 EntryCenters[Profile::SystemMenu::MenuEntriesNumMax];
inline std::vector<int> NavOrder;
inline float FocusScale;
inline float UnfocusedBrightness;

inline int CountMax;

}  // namespace SystemMenu
}  // namespace SG0
}  // namespace Profile
}  // namespace Impacto
