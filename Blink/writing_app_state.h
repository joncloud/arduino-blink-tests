#ifndef WRITING_APP_STATE_H_
#define WRITING_APP_STATE_H_

#include "app_state.h"

class WritingAppState : AppState {
private:
  OutputPin* pin_;
  AppState* next_;
  const int level_;
public:
  WritingAppState(const int level, OutputPin* pin)
    : level_(level), pin_(pin) {
  }
  void set_next(AppState* next) { this->next_ = next; }

  AppState* Update() {
    this->pin_->Write(this->level_);
    return this->next_;
  }
};

#endif

