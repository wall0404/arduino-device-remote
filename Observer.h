#ifndef Observer_h
#define Observer_h


class Observer {
  protected:
    int _mode; // 1=>on/off 2=>videosource1 3=>videosource2
  public:
    virtual ~Observer() {}
    virtual void updateObserver(int mode, int state) = 0;
};

#endif
