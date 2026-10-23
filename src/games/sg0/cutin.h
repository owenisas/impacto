#pragma once

#include <array>

namespace Impacto {
namespace SG0 {

// Slot data at SW_CUTIN1 + 20 * slot: +1..4 source rect, +5..8 destination
// rect (1280x720), +9 alpha, +10 layer.
struct CutinSlot {
  bool Enabled = false;
  int BufferMask = 0;
};

inline std::array<CutinSlot, 4> Cutins;

void RenderCutins(int layer);

}  // namespace SG0
}  // namespace Impacto
