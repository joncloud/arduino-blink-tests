#ifndef DELAYING_APP_STATE_H_
#define DELAYING_APP_STATE_H_

#include "app_state.h"

typedef void (*delayFunc)(long unsigned int);
class DelayingAppState : AppState {
private:
  void (*delay_)(long unsigned int);
  const int time_ms_;
  AppState* next_;
public:
  DelayingAppState(const int time_ms, void (*delay)(long unsigned int), AppState* next)
    : time_ms_(time_ms), delay_(delay), next_(next) { }

  AppState* Update() {
    AppState* state = this->next_->Update();
    (*this->delay_)(this->time_ms_);
    return state;
  }
};

#endif

