#pragma once

#include <il2cpp/il2cpp_helper.h>

enum ToastState {
  Standard                 = 0,
  FactionWarning           = 1,
  FactionLevelUp           = 2,
  FactionLevelDown         = 3,
  FactionDiscovered        = 4,
  IncomingAttack           = 5,
  IncomingAttackFaction    = 6,
  FleetBattle              = 7,
  StationBattle            = 8,
  StationVictory           = 9,
  Victory                  = 10,
  Defeat                   = 11,
  StationDefeat            = 12,
  Tournament               = 14,
  ArmadaCreated            = 15,
  ArmadaCanceled           = 16,
  ArmadaIncomingAttack     = 17,
  ArmadaBattleWon          = 18,
  ArmadaBattleLost         = 19,
  DiplomacyUpdated         = 20,
  JoinedTakeover           = 21,
  CompetitorJoinedTakeover = 22,
  AbandonedTerritory       = 23,
  TakeoverVictory          = 24,
  TakeoverDefeat           = 25
};

struct Toast {
public:
  int get_State()
  {
    static auto prop = get_class_helper().GetProperty("State");
    return *prop.Get<ToastState>((void *)this);
  }

private:
  static IL2CppClassHelper &get_class_helper()
  {
    static auto class_helper = il2cpp_get_class_helper("Assembly-CSharp", "Digit.Prime.HUD", "Toast");
    return class_helper;
  }
};