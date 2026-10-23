#pragma once

#include <cstdint>
#include <vector>

#include "../../vm/thread.h"

namespace Impacto {
namespace UI {
namespace SG0 {

// Reply menus are script blocks 0C(sender, kind) 0D(value, branch)... 0E.
// The chosen branch runs as its own thread.
struct RineMessage {
  int Sender;
  int Kind;   // 0 text, 1 sticker
  int Value;  // _phone string id, or sticker id
};

struct RineReplyOption {
  int Value;
  uint16_t BranchLabel;
};

class Rine {
 public:
  struct Participant {
    uint8_t Avatar;
    uint16_t NameStr;
  };

  void LoadParticipants(uint32_t phoneBuffer, uint16_t label);
  void SelectTextList(uint16_t label);
  void NewThread(int owner);
  void AddMember(int participant);
  void AddMessage(int sender, int kind, int value);
  void ClearAll();
  void SetInput(int textValue);
  void ClearInput();

  void SetReplyMenu(uint32_t scriptBufferId, uint16_t label);
  void CancelReplyMenu();
  bool ReadReplyMenu(int& sender, int& kind,
                     std::vector<RineReplyOption>& options) const;
  void Reply(int optionIndex);
  bool IsBranchThread(const Vm::Sc3VmThread* thread) const;
  void EndBranch(Vm::Sc3VmThread* thread);
  // 0x0F: typing pause before each branch message.
  bool TypingDone();

  void MarkRead();

  int Owner = 0;
  std::vector<int> Members;
  std::vector<RineMessage> Messages;
  int InputText = -1;
  std::vector<Participant> Participants;
  bool MenuPending = false;
  uint64_t Version = 0;  // bumped on every change, for UI relayout

 private:
  uint32_t PhoneBuffer = 0;
  uint32_t MenuBuffer = 0;
  uint16_t MenuLabel = 0;
  uint32_t BranchThreadId = UINT32_MAX;
  int TypingFrames = 0;
};

inline Rine RineState;

}  // namespace SG0
}  // namespace UI
}  // namespace Impacto
