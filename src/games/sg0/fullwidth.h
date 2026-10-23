#pragma once

#include <cstdint>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include "../../profile/dialogue.h"
#include "../../text/fonts/font.h"

namespace Impacto {
namespace UI {
namespace SG0 {

// SG0's font only spaces the full-width Latin glyphs properly.
inline std::string FullWidth(std::string_view ascii) {
  std::string out;
  for (char c : ascii) {
    const uint32_t cp = c == ' '                ? 0x3000
                        : (c > ' ' && c < 0x7F) ? 0xFF01 + (c - '!')
                                                : static_cast<uint8_t>(c);
    if (cp < 0x80) {
      out += static_cast<char>(cp);
    } else {
      out += static_cast<char>(0xE0 | (cp >> 12));
      out += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
      out += static_cast<char>(0x80 | (cp & 0x3F));
    }
  }
  return out;
}

// The font culls glyphs by position, so move them instead of translating.
inline void DrawTextAt(std::span<const ProcessedTextGlyph> text,
                       glm::vec2 offset, float opacity,
                       Fonts::RendererOutlineMode outlineMode) {
  std::vector<ProcessedTextGlyph> moved(text.begin(), text.end());
  for (ProcessedTextGlyph& glyph : moved) glyph.Move(offset);
  Profile::Dialogue::DialogueFont->DrawProcessedText(moved, opacity, opacity,
                                                     outlineMode);
}

}  // namespace SG0
}  // namespace UI
}  // namespace Impacto
