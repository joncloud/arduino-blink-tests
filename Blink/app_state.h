#ifndef APP_STATE_H_
#define APP_STATE_H_

class AppState {
public:
  virtual AppState* Update() = 0;
};

#endif

