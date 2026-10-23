#pragma once

#include "../../../spritesheet.h"

namespace Impacto {
namespace Profile {
namespace SG0 {
namespace SaveMenu {

void Configure();

int constexpr Pages = 6;
int constexpr RowsPerPage = 4;
int constexpr EntriesPerRow = 2;
int constexpr EntriesPerPage = RowsPerPage * EntriesPerRow;

inline Sprite BackgroundSprite;
inline Sprite PanelSprite;
inline glm::vec2 PanelPos;
// Indexed by UI::SaveMenuPageType: QuickLoad, Save, Load.
inline Sprite HeaderSprites[3];
inline glm::vec2 HeaderPos;
inline Sprite ButtonGuideSprite;
inline glm::vec2 ButtonGuidePos;

inline Sprite NoDataSprite;
inline Sprite EntryFrameSprite;
inline Sprite PlayTimeLabelSprite;
inline Sprite SaveDateLabelSprite;
inline Sprite LockedSprite;
inline Sprite PageDigitSprites[7];  // "/" then 1-6

inline glm::vec2 EntryStart;
inline glm::vec2 EntrySpacing;
inline glm::vec2 FrameOffset;
inline glm::vec2 ThumbnailOffset;
inline glm::vec2 ThumbnailSize;
inline glm::vec2 PlayTimeLabelOffset;
inline glm::vec2 SaveDateLabelOffset;
inline glm::vec2 PlayTimeTextOffset;
inline glm::vec2 SaveDateTextOffset;
inline glm::vec2 LockedOffset;
inline glm::vec2 PageNumberPos;
inline float TextFontSize;

inline int SubMenuCountMax;

}  // namespace SaveMenu
}  // namespace SG0
}  // namespace Profile
}  // namespace Impacto
