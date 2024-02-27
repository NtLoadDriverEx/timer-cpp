```cpp
#include "timer.hpp"

// can be defined in function scope as long as it has a static lifetime
// since it stores its time of creation.
static event_timer timer;

int main(){
  timer.reset(); // get current time

  while(true){
    if(timer.has_elapsed(1m))// compare current time to last reset.
      // its been a minute
      timer.reset();
    }
  }
}
```
