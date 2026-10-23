#pragma once

#include "../../ui/menu.h"
#include "../../spritesheet.h"

namespace Impacto {
namespace UI {
namespace SG0 {

class SystemMenu : public Menu {
 public:
  SystemMenu();

  void Show() override;
  void Hide() override;
  void Update(float dt) override;
  void UpdateInput(float dt) override;
  void Render() override;
  void Init() override;

  Sprite ScreenCap;

 private:
  int Cursor = 0;  // index into the navigation order
  bool OpenedAsDirect = false;
  int LastSysMenuCt = 0;
};

}  // namespace SG0
}  // namespace UI
}  // namespace Impacto
