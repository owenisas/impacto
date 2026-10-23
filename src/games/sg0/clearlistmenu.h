#pragma once

#include "../../ui/menu.h"

namespace Impacto {
namespace UI {
namespace SG0 {

class ClearListMenu : public Menu {
 public:
  void Show() override;
  void Hide() override;
  void Update(float dt) override;
  void Render() override;

 private:
  float Alpha() const;
};

}  // namespace SG0
}  // namespace UI
}  // namespace Impacto
