#ifndef __CPPMATH_H__
#define __CPPMATH_H__

class CPPMather {
  public:
    CPPMather(int start);
    void incr();
    void decr();
    int value() const;

  private:
    int val;
};

#endif