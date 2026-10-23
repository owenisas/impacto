#pragma once

#include "../../ui/menu.h"

namespace Impacto {
namespace UI {
namespace SG0 {

class HelpMenu : public Menu {
 public:
  void Show() override;
  void Hide() override;
  void Update(float dt) override;
  void UpdateInput(float dt) override;
  void Render() override;

 private:
  int Page = 0;
  int LastSubMenuCount = 0;
};

}  // namespace SG0
}  // namespace UI
}  // namespace Impacto
