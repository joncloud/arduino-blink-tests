#ifndef APP_H_
#define APP_H_

#include "app_state.h"

class App {
private:
  AppState* current_;
public:
  App(AppState* start)
    : current_(start) {
  }
  void Update() {
    this->current_ = this->current_->Update();
  }
};

#endif

