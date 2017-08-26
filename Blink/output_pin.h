#ifndef OUTPUT_PIN_H_
#define OUTPUT_PIN_H_

class OutputPin {
public:
  virtual void Write(int level) = 0;
};

#endif

