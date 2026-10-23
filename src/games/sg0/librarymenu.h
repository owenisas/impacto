#pragma once

#include <vector>

#include "../../ui/menu.h"
#include "../../text/processedtextglyph.h"

namespace Impacto {
namespace UI {
namespace SG0 {

class LibraryMenu : public Menu {
 public:
  void Init() override;
  void MainTick() { MainCalled = true; }

  void Show() override;
  void Hide() override;
  void Update(float dt) override;
  void UpdateInput(float dt) override;
  void Render() override;

 private:
  enum class Library : int { Cg = 0, Sound = 1, Movie = 2 };

  void SetLibrary(Library library);
  void Back();
  bool AllEndingsCleared() const;
  bool IsCgUnlocked(int entry) const;
  bool IsCgVariationUnlocked(int entry, int variation) const;
  bool IsMovieUnlocked(int movie) const;
  bool IsTrackUnlocked(int track) const;
  int CgCount() const;

  void UpdateCgInput(float dt);
  void UpdateViewerInput(float dt);
  void UpdateSoundInput(float dt);
  void UpdateMovieInput(float dt);
  void UpdateTabInput();
  void UpdatePlayback();

  void OpenViewer(int entry);
  void CloseViewer();
  void RequestCg();
  void ClampViewerPan();
  void PlayTrack(int track);
  void StopTrack();

  void RenderTabs(glm::vec4 tint);
  void RenderGuide(int guide, glm::vec4 tint);
  void RenderCg(glm::vec4 tint);
  void RenderViewer(glm::vec4 tint);
  void RenderSound(glm::vec4 tint);
  void RenderMovie(glm::vec4 tint);

  void LayoutTexts();
  RectF CgCell(int entry) const;
  RectF MovieCell(int movie) const;

  bool Active = false;
  bool MainCalled = false;
  int LastSubMenuCount = 0;
  Library Current = Library::Cg;
  float Time = 0.0f;

  int CgCursor = 0;
  int CgTopRow = 0;

  bool ViewerOpen = false;
  bool ViewerLoaded = false;
  bool ViewerGuide = true;
  int ViewerEntry = 0;
  std::vector<int> ViewerVariations;
  size_t ViewerVariation = 0;
  glm::vec2 ViewerSize{0.0f};
  glm::vec2 ViewerPan{0.0f};
  float ViewerScale = 1.0f;
  float ViewerCoverScale = 1.0f;
  float ViewerContainScale = 1.0f;

  int TrackCursor = 0;
  int TrackTopRow = 0;
  int PlayingTrack = -1;
  int RepeatMode = 0;  // 0 repeat one, 1 play through, 2 repeat all, 3 shuffle
  std::vector<std::vector<ProcessedTextGlyph>> TrackTitles;
  std::vector<std::vector<ProcessedTextGlyph>> TrackArtists;
  std::vector<ProcessedTextGlyph> LockedTrackTitle;

  int MovieCursor = 0;
  std::vector<std::vector<ProcessedTextGlyph>> MovieTitles;
  std::vector<std::vector<ProcessedTextGlyph>> MovieArtists;
  bool TextsLaidOut = false;
};

}  // namespace SG0
}  // namespace UI
}  // namespace Impacto
